class Solution {
public:
    int solve(int i,int prev,vector<pair<int,int>> &arr,vector<vector<int>> &dp){
        if(i==arr.size())   return 0;

        if(dp[i][prev]!=-1) return dp[i][prev];

        int curAge = arr[i].first, prevAge = arr[prev].first;
        int curScore = arr[i].second, prevScore = arr[prev].second;
        
        int ans=0;
        int doNotInclude = 0,include=0,notInclude=0;
        //conflict
        if(prevScore > curScore){
            doNotInclude = solve(i+1,prev, arr,dp);
            ans = doNotInclude;
        }
        else{
            include = curScore + solve(i+1,i, arr,dp);
            notInclude = solve(i+1,prev, arr,dp);
            ans = max(include,notInclude);
        }
        
        return dp[i][prev] = ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();

        vector<pair<int,int>> arr(n+1);
        arr[0] = {-1,-1};
        for(int i=0;i<n;i++){
            arr[i] = {ages[i],scores[i]};
        }

        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,0,arr,dp);
    }
};
