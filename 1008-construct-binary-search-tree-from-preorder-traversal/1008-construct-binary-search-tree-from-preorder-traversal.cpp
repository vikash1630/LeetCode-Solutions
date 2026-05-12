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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder);
    }
    TreeNode* solve(vector<int> preorder) {
        int n = preorder.size();
        if (n == 0) return NULL;
        TreeNode* head = new TreeNode(preorder[0]);
        int x = preorder[0];
        int i = 0;
        for (i = 0;i<n;i++) {
            if (preorder[i] > x) break;
        }
        vector<int> temp(preorder.begin() + 1, preorder.begin() + i);
        TreeNode* left = bstFromPreorder(temp);
        vector<int> temp2(preorder.begin() + i,preorder.begin() + n);
        TreeNode* right = bstFromPreorder(temp2);
        head->left = left;
        head->right = right;
        return head;
    }
};