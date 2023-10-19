class Solution {
public:
    int solve(int i,int prev,vector<int> &arr1,vector<int> &arr2,
        map<pair<int,int>,int> &dp){
        if(i==arr1.size()){
            return 0;
        }

        if(dp.find({i,prev})!=dp.end()) return dp[{i,prev}];

        int ans=INT_MAX/2;
        int idx = upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        //replace it
        if(idx<arr2.size()) ans=min(ans,1+solve(i+1,arr2[idx],arr1,arr2,dp));
        //do not replace it
        if(arr1[i]>prev) ans=min(ans,solve(i+1,arr1[i],arr1,arr2,dp));
        return dp[{i,prev}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        
        map<pair<int,int>,int> dp;
        int ans=solve(0,INT_MIN,arr1,arr2,dp);
        if(ans>=INT_MAX/2)  return -1;
        return ans;
    }
};
