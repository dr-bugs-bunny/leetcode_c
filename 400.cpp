class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9) return n;
        int bit=1;
        while(n>bit*9*pow(10,bit-1))
            n-=bit*9*pow(10,bit++-1);
        int number=(n-1)/bit+pow(10,bit-1);
        return (int)(number/pow(10,bit-1-(n-1)%bit))%10;
    }
};
