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
	int max;
	TreeNode* l, *r, *last;
	void inorder(TreeNode* root)
	{
		if(!root) return;
		inorder(root -> left);
		if(root -> val > max) max = root -> val;
		else if(!l)
		{
			l = last;
			r = root;
			max = root -> val;
		}
		else
		{
			r = root;
			return;
		}
		last = root;
		inorder(root -> right);
	}
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(l && r) swap(l -> val, r -> val);
    }
};