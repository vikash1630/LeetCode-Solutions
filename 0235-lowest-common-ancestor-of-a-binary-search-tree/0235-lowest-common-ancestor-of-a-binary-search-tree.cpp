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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root,q,p);
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        if (root->val > p->val) {
            left = lowestCommonAncestor(root->left,p,q);
        }
        else {
            return lowestCommonAncestor(root->right,p,q);
        }

        if (root->val < q->val) {
            right = lowestCommonAncestor(root->right,p,q);
        }

        if (left == NULL) return right;
        else if (right == NULL) return left;
        else return root;

        // This Works for any binary tree
        // if (root == NULL) return NULL;
        // if (root == p || root == q) return root;
        // TreeNode* left = lowestCommonAncestor(root->left,p,q);
        // TreeNode* right = lowestCommonAncestor(root->right,p,q);
        // if (left == NULL) return right;
        // else if (right == NULL) return left;
        // else return root;
    }
};