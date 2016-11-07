class Solution {
public:
    string getPermutation(int n, int k)
    {
        vector<int> factorial;
        vector<int> unchosen;
        string result = "";
        for(int i = 0; i <= n; i++)
        {
            factorial.push_back(i == 0? 1: factorial[i-1]*i);
            unchosen.push_back(0);
        } 
        
        for(int b = 1; b <= n; b++)
        {
            int number = (k - 1) / factorial[n - b];
            result = result + to_string(unchosen[number + 1]);
            unchosen.erase(unchosen.begin() + number + 1);
            k = k - number * factorial[n - b];
        }

        return result;
    }
};
