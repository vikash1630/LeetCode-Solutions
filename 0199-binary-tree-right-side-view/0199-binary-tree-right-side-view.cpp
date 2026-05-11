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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        map<int,int> mpp;
        queue<pair<int,TreeNode*>> q;
        int cnt = 0;
        q.push({cnt,root});
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                auto p = q.front();
                q.pop();
                int a = p.first;
                TreeNode* node = p.second;
                if (mpp.find(a) == mpp.end()) mpp[a] = node->val;
                if (node->right != NULL) q.push({a+1,node->right});
                if (node->left != NULL) q.push({a+1,node->left});
            }
        }
        for (auto it: mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};