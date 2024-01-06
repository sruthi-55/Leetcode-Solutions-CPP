class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int fuel, vector<int> &locations,int finish,vector<vector<int>> &dp){
        if(fuel<0)  return 0;

        if(dp[i][fuel]!=-1) return dp[i][fuel];

        int ans = 0;
        if(i==finish)   ans++;
        
        for(int next=0;next<locations.size();next++){
            if(i!=next){
                int requiredF = abs(locations[i]-locations[next]);
                ans = (ans+solve(next,fuel-requiredF, locations,finish,dp)%mod)%mod;
            }
        }
        
        return dp[i][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>> dp(n,vector<int>(fuel+1,-1));
        return solve(start,fuel, locations,finish,dp);
    }
};
