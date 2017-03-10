/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> treeStack;
    void pushStack(TreeNode* root)
    {
    	while(root)
    	{
    		treeStack.push(root);
    		root = root ->left;
    	}
    }
public:
    BSTIterator(TreeNode *root) {
       pushStack(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(treeStack.empty()) return false;
        else return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* next = treeStack.top();
        treeStack.pop();
        if(next -> right) pushStack(next -> right);
        return next -> val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */