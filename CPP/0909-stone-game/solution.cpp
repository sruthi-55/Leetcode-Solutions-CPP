class Solution {
public:
    int getMaxAliceScore(int l,int r,vector<int> &piles,vector<vector<int>> &dp){
        if(l>r) return 0;
        if(dp[l][r]!=-1)    return dp[l][r];
        bool isEven = (l-r+1)%2==0 ? true : false;

        int pickLeft=0,pickRight=0;
        if(isEven){
            pickLeft += piles[l];
            pickRight += piles[r];
        }  
        pickLeft += getMaxAliceScore(l+1,r,piles,dp);
        pickRight += getMaxAliceScore(l,r-1,piles,dp);
        return dp[l][r] = max(pickLeft,pickRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        //greedy does not work
        int l=0,r=piles.size()-1;
        int totalSum = accumulate(begin(piles),end(piles),0);

        vector<vector<int>> dp(n,vector<int>(n,-1));
        int aliceScore =  getMaxAliceScore(l,r,piles,dp);
        return aliceScore > totalSum - aliceScore;
    }
};
