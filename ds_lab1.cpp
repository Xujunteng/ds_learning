#include <fstream>
#include <string>

using namespace std;

template <typename T>
struct CellNode {
	T value;
	CellNode* next;
};

template <typename T>
struct RowNode {
	CellNode<T>* cells;
	RowNode* next;
};

template <typename T>
struct Table {
	RowNode<T>* head;
	RowNode<T>* tail;
	int rows;
	int cols;

	Table() : head(nullptr), tail(nullptr), rows(0), cols(0) {}
};

template <typename T>
CellNode<T>* cloneCells(const CellNode<T>* src) {
	CellNode<T>* newHead = nullptr;
	CellNode<T>* newTail = nullptr;
	const CellNode<T>* p = src;
	while (p != nullptr) {
		CellNode<T>* node = new CellNode<T>{p->value, nullptr};
		if (newHead == nullptr) {
			newHead = node;
			newTail = node;
		} else {
			newTail->next = node;
			newTail = node;
		}
		p = p->next;
	}
	return newHead;
}

template <typename T>
CellNode<T>* concatClonedCells(const CellNode<T>* a, const CellNode<T>* b) {
	CellNode<T>* head = cloneCells(a);
	if (head == nullptr) {
		return cloneCells(b);
	}

	CellNode<T>* tail = head;
	while (tail->next != nullptr) {
		tail = tail->next;
	}
	tail->next = cloneCells(b);
	return head;
}

template <typename T>
void appendRow(Table<T>& table, CellNode<T>* cells) {
	RowNode<T>* row = new RowNode<T>{cells, nullptr};
	if (table.head == nullptr) {
		table.head = row;
		table.tail = row;
	} else {
		table.tail->next = row;
		table.tail = row;
	}
	table.rows++;
}

template <typename T>
void freeCells(CellNode<T>* cells) {
	while (cells != nullptr) {
		CellNode<T>* nxt = cells->next;
		delete cells;
		cells = nxt;
	}
}

template <typename T>
void freeTable(Table<T>& table) {
	RowNode<T>* p = table.head;
	while (p != nullptr) {
		RowNode<T>* nxt = p->next;
		freeCells(p->cells);
		delete p;
		p = nxt;
	}
	table.head = nullptr;
	table.tail = nullptr;
	table.rows = 0;
	table.cols = 0;
}

template <typename T>
bool getValueAt(const RowNode<T>* row, int index0, T& outValue) {
	const CellNode<T>* p = row->cells;
	int idx = 0;
	while (p != nullptr) {
		if (idx == index0) {
			outValue = p->value;
			return true;
		}
		idx++;
		p = p->next;
	}
	return false;
}

template <typename T>
Table<T> readTable(ifstream& in, int m, int n) {
	Table<T> table;
	table.cols = n;

	for (int r = 0; r < m; r++) {
		CellNode<T>* rowHead = nullptr;
		CellNode<T>* rowTail = nullptr;
		for (int c = 0; c < n; c++) {
			T value;
			in >> value;
			CellNode<T>* node = new CellNode<T>{value, nullptr};
			if (rowHead == nullptr) {
				rowHead = node;
				rowTail = node;
			} else {
				rowTail->next = node;
				rowTail = node;
			}
		}
		appendRow(table, rowHead);
	}
	return table;
}

template <typename T>
Table<T> buildCartesian(const Table<T>& rTable, const Table<T>& sTable) {
	Table<T> product;
	product.cols = rTable.cols + sTable.cols;

	for (RowNode<T>* rRow = rTable.head; rRow != nullptr; rRow = rRow->next) {
		for (RowNode<T>* sRow = sTable.head; sRow != nullptr; sRow = sRow->next) {
			CellNode<T>* combined = concatClonedCells(rRow->cells, sRow->cells);
			appendRow(product, combined);
		}
	}
	return product;
}

template <typename T>
Table<T> filterGreaterJoin(const Table<T>& product, int rCols, int sCols, int i, int j) {
	Table<T> result;
	result.cols = rCols + sCols;

	if (i < 1 || i > rCols || j < 1 || j > sCols) {
		return result;
	}

	int rIndex = i - 1;
	int sIndexInProduct = rCols + (j - 1);

	for (RowNode<T>* row = product.head; row != nullptr; row = row->next) {
		T rValue = T();
		T sValue = T();
		bool okR = getValueAt(row, rIndex, rValue);
		bool okS = getValueAt(row, sIndexInProduct, sValue);
		if (okR && okS && rValue > sValue) {
			appendRow(result, cloneCells(row->cells));
		}
	}
	return result;
}

template <typename T>
void writeTable(ofstream& out, const Table<T>& table) {
	for (RowNode<T>* row = table.head; row != nullptr; row = row->next) {
		CellNode<T>* cell = row->cells;
		bool first = true;
		while (cell != nullptr) {
			if (!first) {
				out << ' ';
			}
			out << cell->value;
			first = false;
			cell = cell->next;
		}
		out << '\n';
	}
}

void skipUnknownCase(ifstream& in) {
	int m1 = 0, n1 = 0;
	if (!(in >> m1 >> n1)) {
		return;
	}
	string token;
	for (int idx = 0; idx < m1 * n1; idx++) {
		if (!(in >> token)) {
			return;
		}
	}

	int m2 = 0, n2 = 0;
	if (!(in >> m2 >> n2)) {
		return;
	}
	for (int idx = 0; idx < m2 * n2; idx++) {
		if (!(in >> token)) {
			return;
		}
	}

	int i = 0, j = 0;
	in >> i >> j;
}

template <typename T>
void solveOneCase(ifstream& in, ofstream& out) {
	int m1, n1;
	in >> m1 >> n1;
	Table<T> rTable = readTable<T>(in, m1, n1);

	int m2, n2;
	in >> m2 >> n2;
	Table<T> sTable = readTable<T>(in, m2, n2);

	int i, j;
	in >> i >> j;
	if (i < 1 || i > n1 || j < 1 || j > n2) {
		out << "列号超出范围!" << '\n';
		freeTable(rTable);
		freeTable(sTable);
		return;
	}

	Table<T> product = buildCartesian(rTable, sTable);
	Table<T> result = filterGreaterJoin(product, n1, n2, i, j);

	writeTable(out, result);

	freeTable(rTable);
	freeTable(sTable);
	freeTable(product);
	freeTable(result);
}

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");
	if (!in.is_open() || !out.is_open()) {
		return 0;
	}

	int k;
	in >> k;
	for (int caseId = 0; caseId < k; caseId++) {
		string type;
		in >> type;
		out << "第" << (caseId + 1) << "个" << type << "样例:" << '\n';

		if (type == "int") {
			solveOneCase<int>(in, out);
		} else if (type == "char") {
			solveOneCase<char>(in, out);
		} else {
			skipUnknownCase(in);
			out << "未知的数据类型: " << type << '\n';
		}

		if (caseId != k - 1) {
			out << '\n';
		}
	}
	return 0;
}
