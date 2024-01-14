class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if(s.size()<a.size() || s.size()<b.size())  return {};
        vector<int> sAI, sBI;

        for (int i = 0; i <= s.length() - a.length(); ++i) {
            if (s.substr(i, a.length()) == a) {
                sAI.push_back(i);
            }
        }

        for (int i = 0; i <= s.length() - b.length(); ++i) {
            if (s.substr(i, b.length()) == b) {
                sBI.push_back(i);
            }
        }

        
        set<int> resultSet;
        for (int i:sAI) {
            int ind = upper_bound(sBI.begin(),sBI.end(),i-k)-sBI.begin();
            if(ind==sBI.size())  ind = sBI.size()-1;
            for(int j=0;j<=ind;j++){
                if(abs(sBI[j]-i)<=k) resultSet.insert(i);
            }
        }

        vector<int> result(resultSet.begin(), resultSet.end());
        return result;
    }
};
