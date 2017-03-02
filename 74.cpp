#define matrix(x) matrix[x / n][x % n]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int low = 0, high = m*n - 1, mid;
        
        while(low < high)
        {
            mid = (low + high) >> 1;
            if(matrix(mid) < target)
                low = mid + 1;
            else
                high = mid;
        }
        
        if(low == high && matrix(low) == target) 
            return true;
        else 
            return false;
    }
};