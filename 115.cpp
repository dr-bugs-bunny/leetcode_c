class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> count(t.length());
        int s_size = s.length(), t_size = t.length();

        for(int i = 0; i < s_size; i++)
        	for(int j = 0; j < t_size; j++)
        		if(s[i] == t[j]) count[j].push_back(i);

        if(t_size == 1) return count[0].size();

        vector<int> last_count(count[t_size - 1].size(), 1);
        for(int i = t_size - 2; i >= 0; i--)
        {
        	vector<int> i_count = count[i];
        	for(int j = count[i].size() - 1, k = count[i+1].size() - 1, sum = 0; j >= 0; j--)
        	{
        		while(k >= 0 && count[i+1][k] > count[i][j]) 
        		{
        		    sum += last_count[k];
        			k--;
        		}
        		i_count[j] = sum;
        	}
        	last_count = i_count;
        }

        int sum = 0;
        for(auto i : last_count)
        	sum += i;

        return sum;
    }
};
