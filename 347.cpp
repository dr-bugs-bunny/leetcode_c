bool gt(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        for(auto i : nums)
            ++count[i];

        vector< pair<int, int> > count1(count.begin(), count.end());
        sort(count1.begin(), count1.end(), gt);
        
        vector<int> result;
        int i=0; 
        while(i<k) result.push_back(count1[i++].first);

        return result;
    }
};
