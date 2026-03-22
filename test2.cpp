#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> nodes;      // 存储所有已创建的节点

// 在 nodes 中按值查找节点
TreeNode* findNode(int val) {
    for (TreeNode* node : nodes) {
        if (node->val == val) return node;
    }
    return nullptr;
}

// 返回 {height, diameter}
// height: 该节点到其子树中最深叶子的边数
// diameter: 该子树中最大叶子到叶子路径的边数
pair<int, int> dfs(TreeNode* root) {
    if (!root) return { -1, 0 };

    int left_height = 0, right_height = 0;
    int left_diam = 0, right_diam = 0;

    if (root->left) {
        auto left_res = dfs(root->left);
        left_height = left_res.first;
        left_diam = left_res.second;
    }
    if (root->right) {
        auto right_res = dfs(root->right);
        right_height = right_res.first;
        right_diam = right_res.second;
    }

    // 当前节点的高度 = 1 + 子树最大高度；若为叶子则高度为 0
    int my_height;
    if (root->left || root->right) {
        my_height = 1 + max(left_height, right_height);
    } else {
        my_height = 0;
    }

    // 穿过当前节点的路径边数 = 左路径 + 右路径
    int left_path = root->left ? 1 + left_height : 0;
    int right_path = root->right ? 1 + right_height : 0;
    int through = left_path + right_path;

    int my_diam = max({ through, left_diam, right_diam });

    return { my_height, my_diam };
}

int main() {
    int N;
    cin >> N;

    // 读取 N 行节点信息
    for (int i = 0; i < N; i++) {
        string parent_s, left_s, right_s;
        cin >> parent_s >> left_s >> right_s;

        int parent_val = stoi(parent_s);

        // 找到或创建父节点
        TreeNode* parent = findNode(parent_val);
        if (!parent) {
            parent = new TreeNode(parent_val);
            nodes.push_back(parent);
        }

        // 处理左孩子
        if (left_s != "#" && !left_s.empty()) {
            int left_val = stoi(left_s);
            TreeNode* left_child = findNode(left_val);
            if (!left_child) {
                left_child = new TreeNode(left_val);
                nodes.push_back(left_child);
            }
            parent->left = left_child;
        }

        // 处理右孩子
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

    // 空树或单节点
    if (nodes.empty()) {
        cout << 0 << endl;
        return 0;
    }

    TreeNode* root = nodes[0];
    auto result = dfs(root);
    cout << result.second << endl;

    return 0;
}