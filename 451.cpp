class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> count(128);
        string result = "";
        
        for(auto c : s)
        {
            count[(int)c].first++;
            count[(int)c].second = c;
        }
        sort(count.begin(), count.end(), greater<pair<int, int>>());
        for(auto p : count)
        {
            if(!p.first) break;
            else
            {
                string tmp(p.first, (char)p.second);
                result.append(tmp);
            }
        }
        
        return result;
    }
};