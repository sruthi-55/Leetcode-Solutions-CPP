//ASCII values
//'0' - 48
//'9' - 57
//'A' - 65
//'Z' - 90
//'a' - 97
//'z' - 122
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> freq(75);
        for(auto ch:s){
            int f = freq[ch-'0'].second;
            freq[ch-'0'] = {ch,f+1};
        }

        auto myComp = [&](pair<char,int> &p1, pair<char,int> &p2){
            return p1.second > p2.second;
        };
        sort(freq.begin(),freq.end(),myComp);

        string res="";
        for(int i=0;i<75;i++){
            int f = freq[i].second;
            for(int j=0;j<f;j++){
                res.append(1,freq[i].first);
            }
        }
        return res;
    }
};
