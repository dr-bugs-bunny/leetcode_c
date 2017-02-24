typedef vector<int>::iterator v_it;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        pair<v_it, v_it> p = equal_range(nums.begin(), nums.end(), target);
        
        if(p.first == nums.end() || *p.first != target) return (vector<int>({-1,-1}));
        else return (vector<int>({p.first - nums.begin(), p.second - nums.begin() - 1}));
    }
};