#include <cctype>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
	char token;
	Node* left;
	Node* right;
	int val;

	Node(char t) : token(t), left(nullptr), right(nullptr), val(0) {}
	Node(char t, Node* l, Node* r) : token(t), left(l), right(r), val(0) {}
};

static bool isOperand(char c) {
	unsigned char uc = static_cast<unsigned char>(c);
	return isdigit(uc) || isalpha(uc);
}

static int precedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}

static void applyOp(vector<char>& ops, vector<Node*>& nodes) {
	char op = ops.back();
	ops.pop_back();
	Node* right = nodes.back();
	nodes.pop_back();
	Node* left = nodes.back();
	nodes.pop_back();
	nodes.push_back(new Node(op, left, right));
}

static Node* buildTree(const string& expr) {
	vector<char> ops;
	vector<Node*> nodes;
	for (char c : expr) {
		if (isspace(static_cast<unsigned char>(c))) {
			continue;
		}
		if (isOperand(c)) {
			nodes.push_back(new Node(c));
		} else if (c == '(') {
			ops.push_back(c);
		} else if (c == ')') {
			while (!ops.empty() && ops.back() != '(') {
				applyOp(ops, nodes);
			}
			if (!ops.empty() && ops.back() == '(') {
				ops.pop_back();
			}
		} else {
			while (!ops.empty() && ops.back() != '(' && precedence(ops.back()) >= precedence(c)) {
				applyOp(ops, nodes);
			}
			ops.push_back(c);
		}
	}

	while (!ops.empty()) {
		applyOp(ops, nodes);
	}

	return nodes.empty() ? nullptr : nodes.back();
}

static int evalTree(Node* root) {
	if (!root) {
		return 0;
	}
	if (!root->left && !root->right) {
		if (isdigit(static_cast<unsigned char>(root->token))) {
			return root->token - '0';
		}
		return static_cast<int>(root->token);
	}
	int leftVal = evalTree(root->left);
	int rightVal = evalTree(root->right);
	if (root->token == '+') {
		return leftVal + rightVal;
	}
	if (root->token == '-') {
		return leftVal - rightVal;
	}
	if (root->token == '*') {
		return leftVal * rightVal;
	}
	return leftVal / rightVal;
}

static vector<Node*> reverseLevelOrder(Node* root) {
	vector<Node*> order;
	if (!root) {
		return order;
	}
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();
		order.push_back(cur);
		if (cur->left) {
			q.push(cur->left);
		}
		if (cur->right) {
			q.push(cur->right);
		}
	}
	return order;
}

static int evalByReverseLevel(const vector<Node*>& levelOrder) {
	for (auto it = levelOrder.rbegin(); it != levelOrder.rend(); ++it) {
		Node* node = *it;
		if (!node->left && !node->right) {
			if (isdigit(static_cast<unsigned char>(node->token))) {
				node->val = node->token - '0';
			} else {
				node->val = static_cast<int>(node->token);
			}
		} else {
			int leftVal = node->left->val;
			int rightVal = node->right->val;
			if (node->token == '+') {
				node->val = leftVal + rightVal;
			} else if (node->token == '-') {
				node->val = leftVal - rightVal;
			} else if (node->token == '*') {
				node->val = leftVal * rightVal;
			} else {
				node->val = leftVal / rightVal;
			}
		}
	}

	if (levelOrder.empty()) {
		return 0;
	}
	return levelOrder.front()->val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string expr;
	if (!getline(cin, expr)) {
		return 0;
	}

	Node* root = buildTree(expr);
	int value1 = evalTree(root);

	vector<Node*> levelOrder = reverseLevelOrder(root);
	string reversed;
	reversed.reserve(levelOrder.size());
	for (auto it = levelOrder.rbegin(); it != levelOrder.rend(); ++it) {
		reversed.push_back((*it)->token);
	}

	int value2 = evalByReverseLevel(levelOrder);

	cout << value1 << '\n';
	cout << reversed << '\n';
	cout << value2;
	return 0;
}
