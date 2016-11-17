class Solution {
public:
    int nthUglyNumber(int n) {
        long long result = 1, id2 = 0, id3 =0, id5 =0;
        vector<long long> two({2}), three({3}), five({5});
        while(--n)
        {
            if(two[id2] < three[id3] && two[id2] < five[id5])
            {
                if(n == 1) return two[id2];
                two.push_back(two[id2] * 2);
                three.push_back(two[id2] * 3);
                five.push_back(two[id2++] * 5);
            }
            else if(three[id3] < two[id2] && three[id3] < five[id5])
            {
                if(n == 1) return three[id3];
                three.push_back(three[id3] * 3);
                five.push_back(three[id3++] * 5);
            }
            else 
            {
                if(n == 1) return five[id5];
                five.push_back(five[id5++] * 5);
            }
        }
        
        return result;
    }
};
