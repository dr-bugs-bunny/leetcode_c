class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       
       int maxC = 0;
       for(int i = 0; i < nums.size(); i++)
       {
           int count = 0;
           while(i < nums.size() - 1)
           {
               if(nums[i+1] == nums[i] + 1) count++;
               else if(nums[i+1] != nums[i]) break;
               i++;
           }
           maxC = (count > maxC)? count: maxC;
       }
       
       return maxC + 1;
    }
};
