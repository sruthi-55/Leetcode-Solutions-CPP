class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]=i;
            mp2[t[i]]=i;
        } 

        int diff = 0;
        for(auto c:s){
            diff += abs(mp1[c]-mp2[c]);
        }
        return diff;
    }
};
