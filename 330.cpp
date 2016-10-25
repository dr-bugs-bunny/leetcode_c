class Solution {
public:
    int minPatches(vector<int>& nums, int n)
    {
        long long  maxSum, cnt;
        int patch;
        maxSum = cnt = patch = 0;
        while(maxSum < n)
        {
            if(cnt >= nums.size() || maxSum + 1 <= nums[cnt])
            {
                if(cnt < nums.size() && maxSum + 1 == nums[cnt])
                    cnt++;
                else 
                    patch++;
                maxSum = 2 * maxSum + 1;
            }
            else
                maxSum += nums[cnt++];
        }
        return patch;
    }
};
