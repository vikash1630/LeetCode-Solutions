class Solution {
public:
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        if (preorder.size() == 0) return NULL;

        TreeNode* head = new TreeNode(preorder[0]);

        int i = getIndex(inorder, preorder[0]);

        TreeNode* left = buildTree(
            vector<int>(preorder.begin() + 1, preorder.begin() + i + 1),
            vector<int>(inorder.begin(), inorder.begin() + i)
        );

        TreeNode* right = buildTree(
            vector<int>(preorder.begin() + i + 1, preorder.end()),
            vector<int>(inorder.begin() + i + 1, inorder.end())
        );

        head->left = left;
        head->right = right;

        return head;
    }

    int getIndex(vector<int> arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == k) return i;
        }
        return -1;
    }
};