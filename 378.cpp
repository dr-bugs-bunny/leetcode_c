class Solution
{
public:
	int kthSmallest(vector<vector<int>>& matrix, int k)
	{
	    int n = matrix.size();
	    int low = matrix[0][0], sqrtK = sqrt(k), high = sqrtK*sqrtK == k? matrix[sqrtK - 1][sqrtK - 1]: matrix[sqrtK][sqrtK];
	    
	    while(low < high)
	    {
	        int mid = (low + high) >> 1, i = 0, j = n - 1, count = 0;
	        while(i < n && j >= 0)
	        {
	            if(matrix[i][j] > mid) j--;
	            else 
	            {
	                count += j + 1;
	                i++;
	            }
	        }
	        if(count < k)
	            low = mid + 1;
	        else
	            high = mid;
	    }
	    
	    return low;
	}
};