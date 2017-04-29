class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length(), numGroup = (numRows - 1) << 1;
        string r = s;

        for(int row = 0, i = 0; row < numRows && numRows > 1; ++row) {
        	int j = 0;
        	while(j + row < len) {
        		r[i++] = s[j + row];
        		if(row && row < numRows - 1 && j + numGroup - row < len)
        			r[i++] = s[j + numGroup - row];
        		j += numGroup;
        	}
        }

        return r;
    }
};