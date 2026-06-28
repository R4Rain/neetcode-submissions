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

class Solution {
public:
    unordered_set<TreeNode*> visited;
    TreeNode* ans = NULL;

    void dfs(TreeNode* root, int value) {
        if (!root) {
            return;
        }

        if (visited.count(root)) {
            ans = root;
        }

        visited.insert(root);
        if (root->val == value) {
            return;
        } else if (value < root->val) {
            dfs(root->left, value);
        } else {
            dfs(root->right, value);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p->val);
        dfs(root, q->val);
        return ans;
    }
};
