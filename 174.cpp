#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    	int m = dungeon.size(), n = m > 0 ? dungeon[0].size(): 0;
        for(auto &v : dungeon)
        	v.push_back(INT_MIN);
        dungeon.push_back(vector<int>());
        for(int i = 0; i < n; ++i)
        	dungeon[m].push_back(INT_MIN);

        dungeon[m - 1][n] = dungeon[m][n - 1] = - 1;

        for(int i = m -1; i >= 0; --i)
        {
        	for(int j = n - 1; j >= 0; --j)
        	{
        		dungeon[i][j] += max(dungeon[i+1][j], dungeon[i][j+1]);
        		dungeon[i][j] = min(-1, dungeon[i][j]);
        	}
        }

        if(m > 0 && n > 0 && dungeon[0][0] < 0)
            return -dungeon[0][0];
        else
        	return 1;
    }
};