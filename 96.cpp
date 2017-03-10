class Solution {
public:
    int numTrees(int n) {
        vector<int> record(n+1);
        record[0] = record[1] = 1;

        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 1; j <= i; j++)
                sum += record[j-1] * record[i-j];
            record[i] = sum;
        }
            
        return record[n];
    }
};