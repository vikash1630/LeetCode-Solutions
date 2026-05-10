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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                TreeNode* ele = q.front();
                q.pop();
                int h1 = getHeight(ele->left);
                int h2 = getHeight(ele->right);
                ans = max(ans,h1 + h2);
                if (ele->left != NULL) q.push(ele->left);
                if (ele->right != NULL) q.push(ele->right);
            }
        }
        return ans;
    }

    int getHeight(TreeNode* root) {
        if (root == NULL) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left,right) + 1;
    }
};