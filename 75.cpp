class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numSize = nums.size();
        int zeroIn = 0, twoIn = numSize - 1;
        
        for(int i = 0; i < numSize;i++)
        {
            while(zeroIn < numSize && nums[zeroIn] == 0) zeroIn++;
            while(twoIn >= 0 && nums[twoIn] == 2) twoIn--;
            
            if(i >= zeroIn && i <= twoIn)
            {
                if(nums[i] == 0) swap(nums[i], nums[zeroIn++]);
                if(nums[i] == 2) swap(nums[i], nums[twoIn--]);
                if(nums[i] == 0) swap(nums[i], nums[zeroIn++]);
            }
        }
    }
};
