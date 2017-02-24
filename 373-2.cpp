typedef pair<int, pair<int, int>> pairs;
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        int size1 = nums1.size(), size2 = nums2.size();
        if(size1 == 0 || size2 == 0) return result;
                
        priority_queue<pairs, vector<pairs>, greater<pairs>> q;
        
        for(int i = 0; i < size1; i++)
            q.push(make_pair(nums1[i] + nums2[0], make_pair(i, 0)));
            
        while(k-- && !q.empty())
        {
            pairs tmp = q.top();
            q.pop();
            int i = tmp.second.first, j = tmp.second.second;
            result.push_back(make_pair(nums1[i], nums2[j]));
            if(++ j < size2) q.push(make_pair(nums1[i] + nums2[j], make_pair(i, j)));
        }
        
        return result;
    }
};