#include <iostream>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	explicit Node(int v) : key(v), left(nullptr), right(nullptr) {}
};

void insertNode(Node*& root, int key) {
	if (!root) {
		root = new Node(key);
		return;
	}
	if (key < root->key) {
		insertNode(root->left, key);
	} else if (key > root->key) {
		insertNode(root->right, key);
	}
}

Node* findMax(Node* root) {
	while (root && root->right) {
		root = root->right;
	}
	return root;
}

void deleteNode(Node*& root, int key) {
	if (!root) return;
	if (key < root->key) {
		deleteNode(root->left, key);
	} else if (key > root->key) {
		deleteNode(root->right, key);
	} else {
		if (!root->left && !root->right) {
			delete root;
			root = nullptr;
		} else if (!root->left) {
			Node* tmp = root;
			root = root->right;
			delete tmp;
		} else if (!root->right) {
			Node* tmp = root;
			root = root->left;
			delete tmp;
		} else {
			Node* pred = findMax(root->left);
			root->key = pred->key;
			deleteNode(root->left, pred->key);
		}
	}
}

void preorder(Node* root, bool& first) {
	if (!root) return;
	if (!first) cout << ' ';
	cout << root->key;
	first = false;
	preorder(root->left, first);
	preorder(root->right, first);
}

void destroy(Node* root) {
	if (!root) return;
	destroy(root->left);
	destroy(root->right);
	delete root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	if (!(cin >> n)) return 0;

	Node* root = nullptr;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		insertNode(root, x);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		deleteNode(root, x);
	}

	bool first = true;
	preorder(root, first);
	destroy(root);
	return 0;
}
