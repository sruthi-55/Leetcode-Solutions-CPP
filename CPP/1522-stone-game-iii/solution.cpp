class Solution {
public:
    int solve(int i,vector<int> &stones,vector<int> &dp){
        int n=stones.size();
        if(i>=n)    return 0;

        if(dp[i]!=-1)   return dp[i];

        int pickOne = stones[i] - solve(i+1,stones,dp);
        int pickTwo=-1e9,pickThree=-1e9;
        if(i+1<n)   pickTwo = stones[i]+stones[i+1] - solve(i+2,stones,dp);
        if(i+2<n)   pickThree = stones[i]+stones[i+1]+stones[i+2] - solve(i+3,stones,dp);
        
        return dp[i] = max(pickOne,max(pickTwo,pickThree));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,-1);
        int aliceMinusBob = solve(0,stoneValue,dp);
        if(aliceMinusBob == 0)  return "Tie";
        else if(aliceMinusBob > 0)  return "Alice";
        else    return "Bob";
    }
};
