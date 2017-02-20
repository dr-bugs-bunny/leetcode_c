class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            
            if((nums[mid] >= nums[0]) == (target >= nums[0]))
                if(target < nums[mid])
                    high = mid - 1;
                else if(target > nums[mid])
                    low = mid + 1;
                else
                    return mid;
            else
                if(target < nums[0])
                    low = mid + 1;
                else
                    high = mid - 1;
        }
        
        return -1;
    }
};