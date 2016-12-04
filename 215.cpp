class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int numSize = nums.size();
        vector<int> mediums;
        
        for(int i = 0; i < numSize; i += 5)
        {
            if(i + 5 < numSize)
            {
                sort(nums.begin() + i, nums.begin() + i + 5);
                mediums.push_back(nums[i+2]);
            }
            else
            {
                sort(nums.begin() + i, nums.end()); 
                mediums.push_back(nums[i + (numSize - i - 1)/2]);
            }
        }

        sort(mediums.begin(),mediums.end());
        int medium = mediums[(mediums.size() - 1)/2];


        vector<int> partion_nums = nums;
        int head = 0, tail = numSize - 1;
        for(int i = 0; i < numSize; i++)
        {
            if(nums[i] < medium) partion_nums[head++] = nums[i];
            if(nums[i] > medium) partion_nums[tail--] = nums[i];
        }

       if(k >= numSize - tail && k <= numSize - head) return medium;
        else if(tail + k <= numSize)
        {
            partion_nums.erase(partion_nums.begin(), partion_nums.begin() + tail + 1);
            return findKthLargest(partion_nums, k);
        } 
        else
        {
            partion_nums.erase(partion_nums.begin() + head, partion_nums.end());
            return findKthLargest(partion_nums, k - (numSize - head));
        }
    }   
};
