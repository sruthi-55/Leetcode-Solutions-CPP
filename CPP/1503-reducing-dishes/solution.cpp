class Solution {
public:
    int solve(int i,int time,vector<int> &sat,vector<vector<int>> &dp){
        if(i==sat.size())   return 0; 

        if(dp[i][time]!=-1) return dp[i][time];

        int cook = time*sat[i] + solve(i+1,time+1,sat,dp);
        int notCook = solve(i+1,time,sat,dp);

        return dp[i][time] = max(cook,notCook);
    }

    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,1,sat,dp);
    }
};
