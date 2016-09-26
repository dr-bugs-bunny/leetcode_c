class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        stringstream sprint;
        for(int h=0;h<12;h++)
            for(int m=0;m<60;m++){
                bitset<8> hbit(h),mbit(m);
                if(hbit.count()+mbit.count()==num){
                    sprint.str("");
                    sprint<<h<<":"<<(m>9?"":"0")<<m;
                    result.push_back(sprint.str());
                }
            }
        return result;
    }
};
