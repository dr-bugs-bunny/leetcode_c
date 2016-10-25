class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums)
    {
        vector<vector<int> > result;
        vector<int> init = nums;

        while(prev_permutation(nums.begin(), nums.end())) result.push_back(nums);
        result.push_back(init);
        while(next_permutation(init.begin(), init.end())) result.push_back(init);
        
        //sort(result.begin(), result.end());
        return result;
    }
};
