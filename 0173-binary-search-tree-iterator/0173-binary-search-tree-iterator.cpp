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
class BSTIterator {
public:
    vector<int> ans;
    int pos = -1;
    BSTIterator(TreeNode* root) {
        getSize(root);
    }

    void getSize(TreeNode* root) {
        if (root == NULL) return;
        getSize(root->left);
        ans.push_back(root->val);
        getSize(root->right);
    }
    
    int next() {
        pos = pos + 1;
        if (ans.size() <= pos) return -1;
        return ans[pos];
    }
    
    bool hasNext() {
        if (pos + 1 < ans.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */