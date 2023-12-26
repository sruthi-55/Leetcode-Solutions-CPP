class Solution {
public:
    static bool myComp(vector<int> &p1,vector<int> &p2){
        return p1[1]<p2[1];
    }
    int solve(int i,int prevInd,vector<vector<int>> &pairs,vector<vector<int>> &dp){
        if(i==pairs.size()) return 0;

        if(prevInd!=-1)
            if(dp[i][prevInd]!=-1)  return dp[i][prevInd];

        int ans = INT_MIN;
        //can take
        if(prevInd == -1 || pairs[i][0] > pairs[prevInd][1]){
            int take = 1+solve(i+1,i,pairs,dp);
            int notTake = solve(i+1,prevInd,pairs,dp);
            ans = max(take,ans);
        }
        //can't take
        else{
            while(i<pairs.size() && pairs[i][0]<=pairs[prevInd][1])  i++;
            int notTake = solve(i,prevInd,pairs,dp);
            ans = max(ans,notTake);
        }

        if(prevInd!=-1)
            return dp[i][prevInd] = ans;
        return ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),myComp);

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,pairs,dp);
    }
};
