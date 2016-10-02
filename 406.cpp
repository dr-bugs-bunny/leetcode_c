bool greaterequal(pair<int,int> a,pair<int,int> b){return (a.first>b.first||(a.first==b.first&&a.second<=b.second));}
class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        sort(people.begin(),people.end(),greaterequal);
        vector<pair<int,int>> result;
        for (auto person : people){
            result.insert(result.begin() + person.second, person);
        }
        return result;
    }
};
