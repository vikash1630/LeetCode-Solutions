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
    int ans = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int left = dfs(root->left);
        left = max(0,left);
        int right = dfs(root->right);
        right = max(0,right);
        ans = max(ans,left + right + root->val);
        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int a = dfs(root);
        return ans;
    }
};