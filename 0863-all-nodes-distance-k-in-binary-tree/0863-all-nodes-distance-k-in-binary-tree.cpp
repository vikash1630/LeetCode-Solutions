/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mp) {
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                TreeNode* ele = q.front();
                q.pop();
                if (ele->left) {
                    mp[ele->left] = ele;
                    q.push(ele->left);
                }
                if (ele->right) {
                    mp[ele->right] = ele;
                    q.push(ele->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        // if (k == 0) return target;
        if (root == NULL) return ans;
        unordered_map<TreeNode*,TreeNode*> mp;
        getParent(root,mp);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        int dis = 0;
        visited[target] = true;
        while (q.size() != 0) {
            if (dis == k) break;
            int n = q.size();
            for (int i = 0;i<n;i++) {
                TreeNode* ele = q.front();
                q.pop();
                if (ele->left && !visited[ele->left]) {
                    q.push(ele->left);
                    visited[ele->left] = true;
                }
                if (ele->right && !visited[ele->right]) {
                    q.push(ele->right);
                    visited[ele->right] = true;
                }
                if (mp[ele] && !visited[mp[ele]]){
                    q.push(mp[ele]);
                    visited[mp[ele]] = true;
                }
            }
            dis++;
        }
        int n = q.size();
        for (int i = 0;i<n;i++) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};