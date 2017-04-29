class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; ++i) {
        	for(int j = i + 1, k = nums.size() -1; j < k;)
        	{
        		int sum = nums[i] + nums[j] + nums[k];
        		if(abs(closest - target) > abs(sum -target)) closest = sum;
        		if(sum > target) --k;
        		else if(sum < target) ++j;
        		else break;
        	}
        }
        return closest;
    }
};