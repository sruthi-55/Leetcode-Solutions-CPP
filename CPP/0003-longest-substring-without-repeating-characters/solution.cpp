class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxLen=0;
        unordered_set<char> set;
        int l=0,r=0;
        while(r<n) {
            //if right is present in map
            //remove from left until that character is completely removed from map
            if (set.find(s[r])!=set.end()){ 
                while(set.find(s[r])!=set.end()){
                    set.erase(s[l]);
                    l++;
                }
                set.insert(s[r]);
            } 
            else    set.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);  
            r++; 
        }
        return maxLen;
    }
};
