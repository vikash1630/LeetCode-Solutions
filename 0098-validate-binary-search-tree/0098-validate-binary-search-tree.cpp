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
    bool isValidBST(TreeNode* root) {
        long long X = LLONG_MAX; 
        long long Y = LLONG_MIN; 
        return isValid(root,X,Y);
    }
    bool isValid(TreeNode* root,long long maxVal,long long minVal) {
        if (root == NULL) return true;
        if (1LL*root->val >= maxVal || 1LL*root->val <= minVal) return false;
        return (isValid(root->left,root->val,minVal) && isValid(root->right,maxVal,root->val));
    }
};