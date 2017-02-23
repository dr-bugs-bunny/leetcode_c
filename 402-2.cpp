class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack = num;
        int len = num.length();
        
        int bottom = 0, top = -1, pointer = 0;
        while(pointer < len)
        {
            while(k && top >= 0 && num[pointer] < stack[top])
            {
                top--;
                k--;
            }
            stack[++top] = num[pointer++];
        }
        
        while(bottom < top && stack[bottom] == '0') bottom++;
        top -= bottom + k;
        if(top< 0) return "0";
        else return stack.substr(bottom, top + 1);
    }
};