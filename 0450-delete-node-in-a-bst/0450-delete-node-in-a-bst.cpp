/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Handles deletion of a node
    TreeNode* helper(TreeNode* root) {

        // No left child
        if (root->left == NULL) {
            return root->right;
        }

        // No right child
        if (root->right == NULL) {
            return root->left;
        }

        // Both children exist
        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;

        // Find rightmost node of left subtree
        TreeNode* temp = leftSubtree;

        while (temp->right != NULL) {
            temp = temp->right;
        }

        // Attach right subtree
        temp->right = rightSubtree;

        return leftSubtree;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        // Empty tree
        if (root == NULL) {
            return NULL;
        }

        // Delete root node
        if (root->val == key) {
            return helper(root);
        }

        TreeNode* head = root;

        while (root != NULL) {

            // Move Left
            if (key < root->val) {

                // Found node on left side
                if (root->left != NULL &&
                    root->left->val == key) {

                    root->left = helper(root->left);
                    break;
                }

                root = root->left;
            }

            // Move Right
            else {

                // Found node on right side
                if (root->right != NULL &&
                    root->right->val == key) {

                    root->right = helper(root->right);
                    break;
                }

                root = root->right;
            }
        }

        return head;
    }
};