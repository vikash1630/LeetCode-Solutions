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
    TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
        if (postorder.size() == 0) return NULL;
        int n = postorder.size();
        TreeNode* root = new TreeNode(postorder[n - 1]);
        int i = find(inorder,postorder[n - 1]);
        TreeNode* left = buildTree(
            vector<int>(inorder.begin(),inorder.begin() + i),
            vector<int>(postorder.begin(),postorder.begin() + i)
        );
        TreeNode* right = buildTree(
            vector<int>(inorder.begin() + i + 1,inorder.end()),
            vector<int>(postorder.begin() + i,postorder.end() - 1)
        );
        root->left = left;
        root->right = right;
        return root;
    }
    int find(vector<int> arr,int key) {
        for (int i = 0;i<arr.size();i++) {
            if (arr[i] == key) return i;
        }
        return -1;
    }
};