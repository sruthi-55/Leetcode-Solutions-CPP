class Solution {
public:
    int offset = 5000;
    int solve(int i,int diff,vector<int> &rods,vector<vector<int>> &dp){
        if(i==rods.size()){
            if(diff==0)  return 0;
            return INT_MIN;
        }

        if(dp[i][diff+offset]!=-1)   return dp[i][diff+offset];
        //add to support 1
        int addS1 = rods[i]+solve(i+1,diff+rods[i],rods,dp);
        //add to support 2
        int addS2 = solve(i+1,diff-rods[i],rods,dp);
        //add to none
        int doNotAdd = solve(i+1,diff,rods,dp);

        return dp[i][diff+offset]= max({addS1,addS2,doNotAdd});
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        //diff range will be [-5000,5000]
        //so we need to shift indices by 5000
        vector<vector<int>> dp(21, vector<int>(2*offset+1, -1));
        return solve(0,0,rods,dp);
    }
};
