class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string resStr1,resStr2;
        for(auto s:word1)   resStr1+=s;
        for(auto s:word2)   resStr2+=s;
        return resStr1==resStr2;
    }
};
