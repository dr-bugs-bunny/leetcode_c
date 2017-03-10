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
	vector<TreeNode*> generateTrees(int s, int e)
	{
		vector<TreeNode*> roots;
		if(s > e) roots.push_back(nullptr);
		for(int i = s; i <= e; i++)
		{
			for(auto left : generateTrees(s, i-1))
			{
				for(auto right : generateTrees(i+1, e))
				{
					TreeNode* root = new TreeNode(i);
					root -> left = left;
					root -> right = right;
					roots.push_back(root);
				}
			}
		}
		return roots;
	}
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
};