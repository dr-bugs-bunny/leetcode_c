class Solution {
    bool canCross(vector<int>& stones,int cntP,int cntK){
        if(cntP==stones.size()-1) return true;
        bool result=false;
        for(int step=cntK+1;step>=cntK-1&&step>0&&!result;--step){
            vector<int>::iterator it;
            result=result||((it=find(stones.begin()+cntP,stones.end(),stones[cntP]+step))!=stones.end()?canCross(stones,it-stones.begin(),step):false);
        }
        return result;
    }
public:
    bool canCross(vector<int>& stones) {
        int cntP,cntK;
        if(stones[1]==1) cntP=cntK=1;
        else return false;
        for(int i=1;i<stones.size();i++)
            if(stones[i]-stones[i-1]>i) return false;
        return canCross(stones,cntP,cntK);
    }
};
