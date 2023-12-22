class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        //ans == 0's from left + 1's from right
        //ans == zero count + totOnes - one count
        int zeroC=0,oneC=0;
        int ans = INT_MIN;
        for(int i=0;i<=n-2;i++){
            if(s[i]=='0')   zeroC++;
            else    oneC++;
            ans = max(ans, zeroC-oneC);
        }
        if(s[n-1]=='1') oneC++;
        return ans+oneC;
    }
};
