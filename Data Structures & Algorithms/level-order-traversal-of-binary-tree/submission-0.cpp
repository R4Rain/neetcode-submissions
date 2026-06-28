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
    vector<vector<int>> answer;
    void levelOrdering(TreeNode* root, int level) {
        if (!root) {
            return;
        }

        if (level > answer.size()) {
            answer.push_back({root->val});
        } else {
            answer[level-1].push_back(root->val);
        }

        levelOrdering(root->left, level + 1);
        levelOrdering(root->right, level + 1);
    }


    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrdering(root, 1);
        return answer;
    }
};
