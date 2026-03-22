#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> nodes;

TreeNode* findNode(int val) {
    for (TreeNode* node : nodes) {
        if (node->val == val) return node;
    }
    return nullptr;
}

// 判断是否为叶子节点
bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

// 中序遍历收集所有叶子节点（从左到右）
void collectLeaves(TreeNode* root, vector<int>& leaves) {
    if (!root) return;
    collectLeaves(root->left, leaves);
    if (isLeaf(root)) leaves.push_back(root->val);
    collectLeaves(root->right, leaves);
}

// 获取左边界：从根到最左叶子，记录沿途所有节点
vector<int> getLeftBoundary(TreeNode* root) {
    vector<int> boundary;
    TreeNode* curr = root;
    while (curr) {
        boundary.push_back(curr->val);
        if (isLeaf(curr)) break;
        // 优先向左，若左为空则向右
        curr = curr->left ? curr->left : curr->right;
    }
    return boundary;
}

// 获取右边界：从根到最右叶子，逆序记录（从叶子向上，不含根）
vector<int> getRightBoundary(TreeNode* root) {
    vector<int> path_down;  // 从根到最右叶子的路径
    TreeNode* curr = root;
    while (curr) {
        path_down.push_back(curr->val);
        if (isLeaf(curr)) break;
        // 优先向右，若右为空则向左
        curr = curr->right ? curr->right : curr->left;
    }

    // 逆序记录：去掉根，从叶子向上
    vector<int> boundary;
    for (int i = (int)path_down.size() - 1; i >= 1; i--) {
        boundary.push_back(path_down[i]);
    }
    return boundary;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string parent_s, left_s, right_s;
        cin >> parent_s >> left_s >> right_s;

        int parent_val = stoi(parent_s);

        TreeNode* parent = findNode(parent_val);
        if (!parent) {
            parent = new TreeNode(parent_val);
            nodes.push_back(parent);
        }

        if (left_s != "#" && !left_s.empty()) {
            int left_val = stoi(left_s);
            TreeNode* left_child = findNode(left_val);
            if (!left_child) {
                left_child = new TreeNode(left_val);
                nodes.push_back(left_child);
            }
            parent->left = left_child;
        }

        if (right_s != "#" && !right_s.empty()) {
            int right_val = stoi(right_s);
            TreeNode* right_child = findNode(right_val);
            if (!right_child) {
                right_child = new TreeNode(right_val);
                nodes.push_back(right_child);
            }
            parent->right = right_child;
        }
    }

    if (nodes.empty()) return 0;
    TreeNode* root = nodes[0];

    // 1. 左边界：根 → 最左叶子
    vector<int> left_boundary = getLeftBoundary(root);

    // 2. 底层叶子节点（从左到右，去掉左右端点）
    vector<int> all_leaves;
    collectLeaves(root, all_leaves);
    vector<int> mid_leaves;
    if ((int)all_leaves.size() >= 3) {
        for (int i = 1; i < (int)all_leaves.size() - 1; i++) {
            mid_leaves.push_back(all_leaves[i]);
        }
    }

    // 3. 右边界：最右叶子 → 根（逆序记录，不含根）
    vector<int> right_boundary = getRightBoundary(root);

    // 拼接输出
    vector<int> result;
    for (int v : left_boundary) result.push_back(v);
    for (int v : mid_leaves) result.push_back(v);
    for (int v : right_boundary) result.push_back(v);

    for (int i = 0; i < (int)result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}