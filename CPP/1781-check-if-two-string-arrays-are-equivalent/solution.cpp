class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& s1, vector<string>& s2) {
        string fullS1,fullS2;
        for(auto s:s1)  fullS1+=s;
        for(auto s:s2)  fullS2+=s;
        return fullS1==fullS2;
    }
};
