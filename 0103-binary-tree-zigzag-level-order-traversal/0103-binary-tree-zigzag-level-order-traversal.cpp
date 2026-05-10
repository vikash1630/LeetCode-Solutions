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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool flag = true;
        if (root == NULL) return ans;
        q.push(root);
        while (q.size() != 0) {
            int n = q.size();
            vector<int> dum;
            for (int i = 0;i<n;i++) {
                TreeNode* ele = q.front();
                q.pop();
                dum.push_back(ele->val);
                if (ele->left != NULL) q.push(ele->left);
                if (ele->right != NULL) q.push(ele->right);
            }
            if (flag) {
                flag = false;
            }
            else {
                flag = true;
                reverse(dum.begin(),dum.end());
            }
            ans.push_back(dum);
        }
        return ans;
    }
};