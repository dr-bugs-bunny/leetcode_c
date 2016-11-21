class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        
        int numSize = nums.size();
        int halfNum = numSize % 2 ? numSize / 2 : numSize / 2 - 1;
        
        for(int i = halfNum; i >= 0; i--) nums[2*(halfNum-i)] = tmp[i];
        for(int i = numSize - 1; i > halfNum; i--) nums[2*(numSize-i)-1] = tmp[i];
    }
};
