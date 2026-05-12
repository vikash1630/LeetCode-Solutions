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
    TreeNode* first = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* middle = NULL;
    void inOrder(TreeNode* root) {
        if (root == NULL) return;
        inOrder(root->left);
        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inOrder(root);
        if (first && last) swap(first->val,last->val);
        else if (first && middle) swap(first->val,middle->val);
    }
};