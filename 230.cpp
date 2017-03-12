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
    int findKth(TreeNode* root, int& k) {
        if (root) {
            int x = findKth(root->left, k);
            return !k ? x : !--k ? root->val : findKth(root->right, k);
        }
        return 0;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return findKth(root, k);
    }
};