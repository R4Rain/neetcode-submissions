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
    const static int MAX_NEG = -10000001;
    int ans = MAX_NEG;

    int findMaxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftSum = max(0, findMaxPathSum(root->left));
        int rightSum = max(0, findMaxPathSum(root->right));
        int sum = root->val + leftSum + rightSum;
        ans = max(sum, ans);
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        findMaxPathSum(root);
        return ans;
    }
};
