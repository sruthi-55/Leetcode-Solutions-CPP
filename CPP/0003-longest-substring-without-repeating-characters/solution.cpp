class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        int n=s.size();
        unordered_map<int,int> m;
        int l=0,h=0;
        while(h<n){
            //if character already present in map
            if(m.find(s[h])!=m.end()){
                l= max(l,m[s[h]]+1);
                m[s[h]]=h;
            }
            else    m[s[h]]=h;
            maxLen= max(maxLen, h-l+1);
            h++;
        }
        return maxLen;
    }
};
