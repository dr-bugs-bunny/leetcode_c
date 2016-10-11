class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) 
    {
        vector<vector<int> > result;
        unordered_map<string, int> hash;
        for(int i=0; i < words.size(); i++) hash[words[i]] = i+1; 

        for(int i=0; i < words.size(); i++)
        {
            string tmp;      
            int j = 0;
            tmp.assign(words[i].rbegin(),words[i].rend());

            if((j = hash[tmp]) != 0 && j-1 != i) result.push_back(vector<int>({i,j-1}));
            
            for(int k = 0; k < tmp.length(); k++)
            {
                int p=0;
                while(p <= k - p && tmp[p] == tmp[k-p]) p++; 
                if(p > k - p && (j = hash[tmp.substr(k+1, tmp.length()-k-1)]) != 0) 
                    result.push_back(vector<int>({i, j-1}));     
            }

            for(int k = 0; k < words[i].length(); k++)
            {
                int p=0;
                while(p <= k - p && words[i][p] == words[i][k-p]) p++; 
                if(p > k - p && (j = hash[tmp.substr(0, tmp.length()-k-1)]) != 0) 
                    result.push_back(vector<int>({j-1, i}));     
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};
