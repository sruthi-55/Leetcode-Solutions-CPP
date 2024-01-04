class Solution {
public:
    int solve(int i,int daysRem, int maxD, vector<int> &jobDifficulty,
    vector<vector<vector<int>>> &dp){
        if(daysRem==0)  return 1e9;
        if(i==jobDifficulty.size()-1){
            if(daysRem==1)  return max(maxD,jobDifficulty[i]);
            else    return 1e9;
        } 

        if(dp[i][daysRem][maxD]!=-1)    return dp[i][daysRem][maxD];

        //do the job in curr day and end the work for the day
        int endWork = max(maxD,jobDifficulty[i]) + solve(i+1,daysRem-1,0,jobDifficulty,dp);
        //do the job in curr day and continue
        int continueWork = solve(i+1,daysRem,max(maxD,jobDifficulty[i]),jobDifficulty,dp);

        return dp[i][daysRem][maxD] = min(endWork, continueWork);
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        int maxi = *max_element(jobDifficulty.begin(),jobDifficulty.end());

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(d+1,vector<int>(maxi+1,-1)));
        int ans = solve(0,d,0,jobDifficulty,dp);
        if(ans==1e9)    return -1;
        return ans;
    }
};
