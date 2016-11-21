class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        
        while((int)(result.size()) <= num)
        {
            int step = (int)(result.size());
            step = step * 2 <= num + 1 ? step : num + 1 - step;
            for(int i = 0; i < step; i++) result.push_back(result[i] + 1);
        }
        
        return result;
    }
};
