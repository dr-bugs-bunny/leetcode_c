class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int numSize = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < numSize - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int head = i + 1;
            int tail = numSize - 1;
            while(head < tail)
            {
                if(head > i + 1 && nums[head] == nums[head-1]) 
                {
                    head++;
                    continue;
                }
                int sum = nums[i] + nums[head] + nums[tail];
                if(sum == 0)
                {
                    result.push_back(vector<int>{nums[i], nums[head], nums[tail]});
                    head++;
                    tail--;
                }
                else if(sum > 0)
                    tail--;
                else head++;
            }
        }
        
        return result;
    }
};
