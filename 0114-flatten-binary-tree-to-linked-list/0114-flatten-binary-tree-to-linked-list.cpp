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
    vector<int> ans;
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        preOrder(root);
        for (int i = 0;i<ans.size() - 1;i++) {
            root->val = ans[i];
            root->left = NULL;
            if (!root->right) root->right = new TreeNode();
            root = root->right;
        }
        root->val = ans[ans.size() - 1];
        root->left = NULL;
        root->right = NULL;

    }
    void preOrder(TreeNode* root) {
        if (root == NULL) return;
        ans.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};