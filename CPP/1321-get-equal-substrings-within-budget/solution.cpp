class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int maxLen = 0;
        int i=0,j=0;
    
        int curCost = 0;
        while(j<n){
            curCost += abs(s[j]-t[j]);
            while(i<n && curCost>maxCost){
                curCost -= abs(s[i]-t[i]);
                i++;
            }   
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};
