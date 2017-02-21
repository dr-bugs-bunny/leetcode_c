class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while(low < high)
        {
            int mid = (low + high) >> 1;
            if((nums[mid] >= nums[0]) == (nums[high] >= nums[0]))
                high = mid;
            else low = mid + 1;
        }
        
        if(high < 0) return NULL;
        else return nums[high];
    }
};