/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // preorder 1 2 3 4
 // inorder 2 1 3 4
       // m = 1

 //      2 1 3 4
 //    2     3 4
 //             4
 // f(0, 1)

class Solution {
public:
    int size, idx;
    unordered_map<int, int> inorderIdx;    

    TreeNode* divide(int l, int r, vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root = NULL;
        if (idx >= size) {
            return root;
        }

        int nodeValue = preorder[idx];
        int m = inorderIdx[nodeValue];
        if (l <= m && m <= r) {
            root = new TreeNode(nodeValue);
            idx++;
            root->left = divide(l, m-1, preorder, inorder);
            root->right = divide(m+1, r, preorder, inorder);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size = preorder.size();
        for (int i = 0;i < inorder.size();i++) {
            inorderIdx[inorder[i]] = i;
        }
        idx = 0;
        TreeNode* root = divide(0, size-1, preorder, inorder);
        return root;
    }
};
