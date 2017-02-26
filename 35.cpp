class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size(), mid;
        
        while(low < high)
        {
            mid = (low + high) >> 1;
            if(nums[mid] < target)
                low = mid + 1;
            else 
                high = mid;
        }
        
        return low;
    }
};