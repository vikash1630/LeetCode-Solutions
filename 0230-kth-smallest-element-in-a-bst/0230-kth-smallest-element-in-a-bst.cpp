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
    int dfs(TreeNode* root,int& cnt,int k) {
        if (root == NULL) return -1;
        int left = dfs(root->left,cnt,k);
        if (left != -1) return left;
        cnt++;
        if (cnt == k) return root->val;
        int right = dfs(root->right,cnt,k);
        if (right != -1) return right;   
        return -1;
    } 
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return dfs(root,cnt,k);
    }
};