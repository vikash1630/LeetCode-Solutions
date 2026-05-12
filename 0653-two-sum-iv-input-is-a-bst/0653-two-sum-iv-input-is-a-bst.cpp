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
    unordered_map<int,int> mpp;
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        int target = k - root->val;
        if (mpp.find(target) != mpp.end()) return true;
        mpp[root->val] = 1;
        bool left = findTarget(root->left,k);
        if (left) return true;
        return findTarget(root->right,k);
    }
};