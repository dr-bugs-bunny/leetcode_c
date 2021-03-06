class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin() + m + n, nums1.end());
        for(int i = m - 1, j = n - 1, cnt = m + n - 1; cnt >= 0; cnt--)
        {
            if(i < 0) nums1[cnt] = nums2[j--];
            else if(j < 0) nums1[cnt] = nums1[i--];
            else
            {
                if(nums1[i] >= nums2[j]) nums1[cnt] = nums1[i--];
                else nums1[cnt] = nums2[j--];
            }
        }
    }
};