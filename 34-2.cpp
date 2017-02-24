class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while(low < high)
        {
            int mid = (low + high) >> 1;
            if(nums[mid] < target) 
                low = mid + 1;
            else
                high = mid;
        }
        
        while(low > 0 && nums[low - 1] == target) low--;
        while(high < nums.size() - 1 && nums[high + 1] == target) high++;
        
        if(nums.size() == 0 || nums[low] != target) return vector<int>({-1,-1});
        else return vector<int>({low, high});
    }
};