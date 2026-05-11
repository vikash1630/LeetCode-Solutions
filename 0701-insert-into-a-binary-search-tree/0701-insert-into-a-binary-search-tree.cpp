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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        TreeNode* head = root;
        TreeNode* attach = root;
        while (root != NULL) {
            attach = root;
            if (root->val > val) root = root->left;
            else root = root->right;
        }
        if (attach->val > val) {
            attach->left = new TreeNode(val);
        }
        else attach->right = new TreeNode(val);
        return head;
    }
};