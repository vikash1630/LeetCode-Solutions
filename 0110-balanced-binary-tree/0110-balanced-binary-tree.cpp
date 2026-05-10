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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int h1 = 0;
        if (root->left) h1 = height(root->left);
        int h2 = 0;
        if (root->right) h2 = height(root->right);
        if (abs(h1 - h2) > 1) return false;
        bool left = isBalanced(root->left); 
        bool right = isBalanced(root->right); 
        if (!left || !right) return false;
        return true;
    }

    int height(TreeNode* root) {
    if (root == NULL) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int cnt = 0;

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            TreeNode* ele = q.front();
            q.pop();

            if (ele->left) q.push(ele->left);
            if (ele->right) q.push(ele->right);
        }

        cnt++;
    }

    return cnt;
}
};