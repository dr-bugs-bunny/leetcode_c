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
    TreeNode* sortedArrayToBST(vector<int> &nums, int low, int high) {
        if(low > high) return nullptr;

        int mid = (low + high) >> 1;
        TreeNode *tmp = new TreeNode(nums[mid]);
        tmp -> left = sortedArrayToBST(nums, low, mid - 1);
        tmp -> right = sortedArrayToBST(nums, mid + 1, high);

        return tmp;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};