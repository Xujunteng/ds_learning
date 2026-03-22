#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int main() {
    int N;
    cin >> N;

    // --- 构建二叉树（BFS 顺序输入，无需 map）---
    Node* root = nullptr;
    queue<Node*> q;  // 存放尚未处理孩子信息的结点

    for (int i = 0; i < N; i++) {
        int val;
        string leftStr, rightStr;
        cin >> val >> leftStr >> rightStr;

        Node* cur;
        if (i == 0) {
            // 第一行是根结点
            root = new Node(val);
            cur = root;
        } else {
            // 后续行：队首结点即为当前行描述的结点
            cur = q.front();
            q.pop();
        }

        // 处理左孩子
        if (leftStr != "#") {
            Node* leftChild = new Node(stoi(leftStr));
            cur->left = leftChild;
            q.push(leftChild);
        }

        // 处理右孩子
        if (rightStr != "#") {
            Node* rightChild = new Node(stoi(rightStr));
            cur->right = rightChild;
            q.push(rightChild);
        }
    }

    // --- DFS 寻找最大瓶颈路径 ---
    int bestBottleneck = -1;
    vector<int> bestPath;
    vector<int> curPath;

    // 匿名递归 lambda（C++14）
    auto dfs = [&](auto&& self, Node* node, int curMin) -> void {
        if (!node) return;

        curPath.push_back(node->val);
        int newMin = min(curMin, node->val);

        // 叶子结点：检查是否更优
        if (!node->left && !node->right) {
            if (newMin > bestBottleneck) {
                bestBottleneck = newMin;
                bestPath = curPath;
            }
        } else {
            // 先左后右（DFS 顺序保证首次遇到即最优）
            if (node->left)  self(self, node->left,  newMin);
            if (node->right) self(self, node->right, newMin);
        }

        curPath.pop_back();  // 回溯
    };

    dfs(dfs, root, root->val);

    // --- 输出 ---
    cout << bestBottleneck << endl;
    for (size_t i = 0; i < bestPath.size(); i++) {
        if (i > 0) cout << " ";
        cout << bestPath[i];
    }
    cout << endl;

    return 0;
}
