class Solution {
public:
    int solve(int i,vector<int> &arr,map<int,int> &map,vector<int> &dp){
        if(i==arr.size())   return 0;

        if(dp[i]!=-1)   return dp[i];

        int ans = INT_MIN;
        int take = arr[i]*map[arr[i]];
        if(i+1<arr.size() && arr[i+1]==arr[i]+1)  
            take += solve(i+2,arr,map,dp);
        else if(i+1<arr.size() && arr[i+1]!=arr[i]+1)  
            take += solve(i+1,arr,map,dp);

        int notTake = solve(i+1,arr,map,dp);

        return dp[i] = max(take,notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        map<int,int> map;
        for(auto e:nums)    map[e]++;

        vector<int> arr;
        for(auto e:map) arr.push_back(e.first);

        vector<int> dp(n,-1);
        return solve(0,arr,map,dp);
    }
};
