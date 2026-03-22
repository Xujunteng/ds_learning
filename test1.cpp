#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

// 二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> nodes;      // 存储所有已创建的节点
int max_bottleneck = -1;      // 最大瓶颈值
vector<int> best_path;        // 最优路径

// 在 nodes 中按值查找节点
TreeNode* findNode(int val) {
    for (TreeNode* node : nodes) {
        if (node->val == val) return node;
    }
    return nullptr;
}

// DFS 遍历，cur_min 记录当前路径上的最小值
void dfs(TreeNode* root, vector<int>& cur_path, int cur_min) {
    if (!root) return;

    cur_path.push_back(root->val);
    if (root->val < cur_min) cur_min = root->val;

    // 到达叶子节点
    if (!root->left && !root->right) {
        if (cur_min > max_bottleneck) {
            max_bottleneck = cur_min;
            best_path = cur_path;
        }
    }

    // 先左后右深度优先
    dfs(root->left, cur_path, cur_min);
    dfs(root->right, cur_path, cur_min);

    cur_path.pop_back();  // 回溯
}

int main() {
    int N;
    cin >> N;

    // 读取 N 行，每行三个字符串：父节点值 左孩子值 右孩子值
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

    // 第一个节点为根
    TreeNode* root = (nodes.empty() ? nullptr : nodes[0]);

    if (!root) {
        cout << 0 << endl;
        return 0;
    }

    // DFS 搜索最大瓶颈路径
    vector<int> cur_path;
    dfs(root, cur_path, INT_MAX);

    // 输出结果
    cout << max_bottleneck << endl;
    for (size_t i = 0; i < best_path.size(); i++) {
        if (i > 0) cout << " ";
        cout << best_path[i];
    }
    cout << endl;

    return 0;
}