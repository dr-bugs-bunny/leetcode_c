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
	int result, lastValue;
	void inorder(TreeNode* root)
	{
		if(!root) return;
		inorder(root -> left);
		if(lastValue < root -> val) 
			result = min(root -> val - lastValue, result);
		lastValue = root -> val;
		inorder(root -> right);
	}
public:
    int getMinimumDifference(TreeNode* root) {
        result = lastValue = INT_MAX;
        inorder(root);
        return result;
    }
};