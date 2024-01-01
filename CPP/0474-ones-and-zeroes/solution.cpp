class Solution {
public:
    pair<int,int> getCount(string s){
        int n=s.size();
        int zC=0,oC=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')   zC++;
            else    oC++;
        }
        return {zC,oC};
    }
    int solve(int i,int zeroes,int ones,int m,int n,vector<string> &strs,vector<vector<vector<int>>> &dp){
        if(i>=strs.size())  return 0;
        if(zeroes>m || ones>n)  return  0;
        
        if(dp[i][zeroes][ones]!=-1) return dp[i][zeroes][ones];

        pair<int,int> count = getCount(strs[i]);
        int take=0,notTake=0,cannotTake=0;

        int newZ = zeroes+count.first;
        int newO = ones+count.second;
        if(newZ<=m && newO<=n){
            take = 1 + solve(i+1,newZ,newO, m,n,strs,dp);
            notTake = solve(i+1,zeroes,ones, m,n,strs,dp);
        }
        else cannotTake = solve(i+1,zeroes,ones, m,n,strs,dp);

        return dp[i][zeroes][ones] = max({take,notTake,cannotTake});
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),
            vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,0,0, m,n,strs,dp);
    }
};
