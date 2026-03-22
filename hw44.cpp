#include <iostream>
#include <vector>
using namespace std;

// 二叉树结点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 从层序遍历数组构建二叉排序树
// 结点 i 的左孩子在 2i+1，右孩子在 2i+2（-1表示空结点）
TreeNode* buildBST(const vector<int>& levelOrder, int n) {
    if (n == 0 || levelOrder[0] == -1) return nullptr;
    
    vector<TreeNode*> nodes(n, nullptr);
    TreeNode* root = new TreeNode(levelOrder[0]);
    nodes[0] = root;
    
    for (int i = 0; i < n; i++) {
        if (nodes[i] == nullptr) continue;
        
        int leftIdx = 2 * i + 1;
        int rightIdx = 2 * i + 2;
        
        if (leftIdx < n && levelOrder[leftIdx] != -1) {
            nodes[i]->left = new TreeNode(levelOrder[leftIdx]);
            nodes[leftIdx] = nodes[i]->left;
        }
        
        if (rightIdx < n && levelOrder[rightIdx] != -1) {
            nodes[i]->right = new TreeNode(levelOrder[rightIdx]);
            nodes[rightIdx] = nodes[i]->right;
        }
    }
    
    return root;
}

// 利用BST性质查找第一个大于k的结点值（ceiling）
int findFirstGreater(TreeNode* root, int k) {
    int result = -1;
    TreeNode* cur = root;
    
    while (cur != nullptr) {
        if (cur->val > k) {
            // 当前结点值 > k，记录候选，继续往左找更小的候选
            result = cur->val;
            cur = cur->left;
        } else {
            // 当前结点值 <= k，往右找更大的值
            cur = cur->right;
        }
    }
    
    return result;
}

// 释放树的内存
void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> levelOrder(n);
    for (int i = 0; i < n; i++) {
        cin >> levelOrder[i];
    }
    
    int k;
    cin >> k;
    
    TreeNode* root = buildBST(levelOrder, n);
    int result = findFirstGreater(root, k);
    
    cout << result << endl;
    
    freeTree(root);
    return 0;
}
