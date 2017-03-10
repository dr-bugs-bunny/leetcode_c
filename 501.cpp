class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(root)
        {
            TreeNode* r = root;
            while(r -> right != nullptr) r = r -> right;
            end = r -> val;
            r -> right =  new TreeNode(end + 1);
        } 
        
        inorder(root);
        return result;
    }
private:
    vector<int> result;
    int end;
    int maxCount = 0, cntVal, cntCount = 0;

    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root -> left);
        if(root -> val != cntVal)
        {
            if(cntCount > maxCount)
            {
                maxCount = cntCount;
                result.erase(result.begin(), result.end());
                result.push_back(cntVal);
            }
            else if(cntCount == maxCount) 
                result.push_back(cntVal);
            cntVal = root -> val;
            cntCount = 1;
        }
        else
            cntCount++;
        inorder(root -> right);
    }
};