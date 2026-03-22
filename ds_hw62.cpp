#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int main() {
    int n;
    cin >> n;

    // Read the level-order array from the second line
    cin.ignore();
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> nodes;
    int val;
    while (ss >> val) {
        nodes.push_back(val);
    }

    int k;
    cin >> k;

    if (nodes.empty()) {
        cout << -1 << endl;
        return 0;
    }

    // Build tree from level-order representation
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int idx = 1;
    int m = (int)nodes.size();

    while (!q.empty() && idx < m) {
        TreeNode* cur = q.front();
        q.pop();

        // Left child
        if (idx < m && nodes[idx] != -1) {
            cur->left = new TreeNode(nodes[idx]);
            q.push(cur->left);
        }
        idx++;

        // Right child
        if (idx < m && nodes[idx] != -1) {
            cur->right = new TreeNode(nodes[idx]);
            q.push(cur->right);
        }
        idx++;
    }

    // Find the first value > k (smallest value > k in BST)
    int ans = -1;
    TreeNode* cur = root;
    while (cur) {
        if (cur->val > k) {
            ans = cur->val;
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    cout << ans << endl;

    return 0;
}