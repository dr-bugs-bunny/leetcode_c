class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        vector<pair<int, int> > trace;
        pair<int, int> cntP({0,0});
        trace.push_back(cntP);

        for(int i = 0; i < x.size(); i++)
        {
            cntP.first += (i % 2 == 1)?(i % 4 == 3? 1 : -1)*x[i] : 0;
            cntP.second += (i % 2 == 0)?(i % 4 == 0? 1 : -1)*x[i] : 0;
            trace.push_back(cntP);

            if(i == 4 && cntP.first == 0 && cntP.second >= 0) return true;
            for(int step = 5; step <= trace.size(); step += 2)
            {
                pair<int, int> cntP1, cntP2, cntP3, cntP4;
                cntP1 = trace[trace.size()-1];
                cntP2 = trace[trace.size()-2];
                cntP3 = trace[trace.size()-step+1];
                cntP4 = trace[trace.size()-step];

                if(i % 2 == 0 
                    && (cntP1.first <= max(cntP3.first, cntP4.first) && cntP1.first >= min(cntP3.first, cntP4.first)) 
                    && (cntP3.second <= max(cntP1.second, cntP2.second) && cntP3.second >= min(cntP1.second, cntP2.second)) 
                  )
                    return true;
                else if((cntP1.second <= max(cntP3.second, cntP4.second) && cntP1.second >= min(cntP3.second, cntP4.second))                                       
                       && (cntP3.first <= max(cntP1.first, cntP2.first) && cntP3.first >= min(cntP1.first, cntP2.first))) 
                    return true;
            }
            
            if(trace.size() > 6) trace.erase(trace.begin());
        }
        return false;
    }
};

