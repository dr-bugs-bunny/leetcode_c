class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < (int)nums.size(); i++)
        {
            while(i >= 2 && i < (int)nums.size() && nums[i] == nums[i-2])
                nums.erase(nums.begin() + i);
        }
        
        return nums.size();
    }
};