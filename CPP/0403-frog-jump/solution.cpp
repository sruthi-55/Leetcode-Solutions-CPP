class Solution {
public:
    bool solve(int i,int prevJump,unordered_map<int,int> &mp,vector<int> &stones,vector<vector<int>> &dp){
        if(i==stones.size()-1)    return true;
        if(i>stones.size()) return false;
    
        if(dp[i][prevJump]!=-1) return dp[i][prevJump];

        bool ans = false;
        for(int nJump=prevJump-1; nJump<=prevJump+1; nJump++){
            if(nJump>0){
                int nStone = stones[i]+nJump;
                if(mp.find(nStone)!=mp.end())
                    ans = ans || solve(mp[nStone],nJump, mp,stones,dp);
            }
        }
        return dp[i][prevJump] = ans;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=1)    return false;

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }

        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(1,1,mp,stones,dp);
    }
};


