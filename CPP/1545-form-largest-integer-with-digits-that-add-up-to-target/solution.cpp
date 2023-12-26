class Solution {
public:
string getBigger(string& s1, string& s2) {
        string t = "0";
        if (s1.find(t) != std::string::npos) return s2;
        if (s2.find(t) != std::string::npos) return s1;
        if (s1.length() > s2.length())
            return s1;
        else
            return s2;
    }
    string solve(int i,int target,vector<int> &cost,vector<vector<string>> &dp){
        if (target == 0) return "";                        
        if (target < 0) return "0";  
        if(i==cost.size())  return "0";

        if(dp[i][target]!="-1")   return dp[i][target];

        string take = to_string(i+1) + solve(0,target-cost[i],cost,dp);
        string notTake = solve(i+1,target,cost,dp);
        
        return dp[i][target] = getBigger(take,notTake);
    }
    string largestNumber(vector<int>& cost, int target) {
        int n=cost.size();
        vector<vector<string>> dp(n+1,vector<string>(target+1,"-1"));
        return solve(0,target,cost,dp);
    }
};
