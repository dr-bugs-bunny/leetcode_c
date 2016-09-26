class Solution {
public:
    string removeKdigits(string num, int k) {
        num+="0";
        string::iterator it=num.begin();
        while(it!=num.end()){
            while(it!=num.begin()&&*it<*(it-1)&&k-->0) num.erase(it---1);
            it++;
        }
        while(!num.empty()&&num[0]=='0') num=num.substr(1,num.size()-1);
        if(num.size()>1) return num.substr(0,num.size()-1);
        else return "0";
    }
};
