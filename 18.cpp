class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int numSize = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < numSize - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < numSize - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int head = j + 1;
                int tail = numSize - 1;
                while(head < tail)
                {
                    if(head > j + 1 && nums[head] == nums[head-1]) 
                    {
                        head++;
                        continue;
                    }
                    int sum = nums[i] + nums[j] + nums[head] + nums[tail];
                    if(sum == target)
                    {
                        result.push_back(vector<int>{nums[i], nums[j], nums[head], nums[tail]});
                        head++;
                        tail--;
                    }
                    else if(sum > target)
                        tail--;
                    else head++;
                }
            }
        }
        
        return result;
    }
};
