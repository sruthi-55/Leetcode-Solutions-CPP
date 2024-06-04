class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mp;
        for(auto c:s)   mp[c]++;

        int maxLen = 0;
        bool hasOdd = false;
        for(auto e:mp){
            int freq = e.second;
            if(freq%2!=0){
                hasOdd = true;
            }
            maxLen += e.second/2;
        }
        if(hasOdd)  return 1+2*maxLen;
        return 2*maxLen;
    }
};
