class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        int size1 = nums1.size(), size2 = nums2.size();
        if(size1 == 0 || size2 == 0) return result;
        k = k > size1 * size2 ? size1 * size2 : k;
        
        int low = nums1[0] + nums2[0], high = nums1[size1-1] + nums2[size2-1];
        while(low < high)
        {
            int mid = (low + high) >> 1, count = 0, i = 0;
            while(i < size1)
            {
                int j = 0;
                while(nums1[i] + nums2[j] <= mid && j < size2) j++;
                count += j;
                i++;
            }
            if(count < k)
                low = mid + 1;
            else
                high = mid;
        }
        
        vector<pair<int,int>> tmp;
        for(int i = 0; i < size1 && k; i++)
        {
            for(int j = 0; j < size2 && k; j++)
            {
                if(nums1[i] + nums2[j] > low) break;
                if (nums1[i] + nums2[j] < low)
                {
                    k--;
                    result.push_back(make_pair(nums1[i], nums2[j]));
                }
                else 
                    tmp.push_back(make_pair(nums1[i], nums2[j]));
            }
        }
        while(k) result.push_back(tmp[--k]);
        return result;
    }
};