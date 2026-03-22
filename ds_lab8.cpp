#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct BTnode {
	int data;
	int cnt;
	BTnode* lchild;
	BTnode* rchild;

	BTnode(int x) : data(x), cnt(1), lchild(nullptr), rchild(nullptr) {}
};

class BTree {
public:
	BTnode* root;
	string repr;

	BTree() : root(nullptr) {}

	BTnode* insert(BTnode* r, int x) {
		if (r == nullptr) {
			return new BTnode(x);
		}
		if (x < r->data) {
			r->lchild = insert(r->lchild, x);
		} else if (x > r->data) {
			r->rchild = insert(r->rchild, x);
		} else {
			r->cnt++;
		}
		return r;
	}

	BTnode* extractMin(BTnode*& r) {
		if (r->lchild == nullptr) {
			BTnode* node = r;
			r = r->rchild;
			node->rchild = nullptr;
			return node;
		}
		return extractMin(r->lchild);
	}

	BTnode* removeOne(BTnode* r, int x) {
		if (r == nullptr) {
			return nullptr;
		}
		if (x < r->data) {
			r->lchild = removeOne(r->lchild, x);
		} else if (x > r->data) {
			r->rchild = removeOne(r->rchild, x);
		} else {
			if (r->cnt > 1) {
				r->cnt--;
				return r;
			}
			if (r->lchild == nullptr) {
				BTnode* right = r->rchild;
				delete r;
				return right;
			}
			if (r->rchild == nullptr) {
				BTnode* left = r->lchild;
				delete r;
				return left;
			}
			BTnode* succ = extractMin(r->rchild);
			r->data = succ->data;
			r->cnt = succ->cnt;
			delete succ;
		}
		return r;
	}

	void preorderBracket(BTnode* r) {
		if (r == nullptr) {
			return;
		}
		repr += to_string(r->data);
		repr += '|';
		repr += to_string(r->cnt);
		if (r->lchild == nullptr && r->rchild == nullptr) {
			return;
		}
		repr += '(';
		if (r->lchild != nullptr) {
			preorderBracket(r->lchild);
		}
		repr += ',';
		if (r->rchild != nullptr) {
			preorderBracket(r->rchild);
		}
		repr += ')';
	}

	void inorderValues(BTnode* r, vector<int>& values) {
		if (r == nullptr) {
			return;
		}
		inorderValues(r->lchild, values);
		values.push_back(r->data);
		inorderValues(r->rchild, values);
	}
};

static int binarySearchCount(const vector<int>& values, int target) {
	int left = 0;
	int right = static_cast<int>(values.size()) - 1;
	int compareCount = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		compareCount++;
		if (values[mid] == target) {
			return compareCount;
		}
		if (values[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return compareCount;
}

int main() {

	BTree t;

	string firstLine;
	while (getline(cin, firstLine)) {
		if (firstLine.find_first_not_of(" \t\r\n") != string::npos) {
			break;
		}
	}

	if (firstLine.empty()) {
		return 0;
	}

	stringstream ss(firstLine);
	int value;
	while (ss >> value) {
		t.root = t.insert(t.root, value);
	}

	int x, y;
	cin >> x;
	cin >> y;

	t.repr.clear();
	t.preorderBracket(t.root);
	cout << t.repr << '\n';

	t.root = t.removeOne(t.root, x);

	vector<int> inorderSeq;
	t.inorderValues(t.root, inorderSeq);
	for (int i = 0; i < static_cast<int>(inorderSeq.size()); ++i) {
		if (i > 0) {
			cout << ' ';
		}
		cout << inorderSeq[i];
	}
	cout << '\n';

	cout << binarySearchCount(inorderSeq, y);
	return 0;
}
