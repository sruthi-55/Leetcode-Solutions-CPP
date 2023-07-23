class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        //     j   0   1   2   3   4   5   6
        //  i      r   a   c   e   c   a   r
        //  0  r   T   F   F   F   F   F   #
        //  1  a       T   F   F   F   #   F
        //  2  c           T   F   T   F   F
        //  3  e               T   F   F   F
        //  4  c                   T   F   F
        //  5  a                       T   F
        //  6  r                           T

        for(int diff=0;diff<n;diff++){
            for(int i=0,j=diff;j<n;i++,j++){
                if(diff==0) dp[i][j]=true;
                else if(diff==1 && s[i]==s[j])  dp[i][j]=true;
                else{
                    if(s[i]==s[j])
                        dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j])  count++;
            }
        }
        return count;
    }
};
