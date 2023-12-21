class Solution {
public:
    int binarySearch(vector<vector<int>> &jobs,int l,int target){
        int h=jobs.size()-1;
        int ans = h+1;
        while(l<=h){
            int mid= l+(h-l)/2;
            if(jobs[mid][0]>=target){
                ans=mid;
                h=mid-1;
            }
            else    l=mid+1;
        }
        return ans;
    }
    int solve(int i,vector<vector<int>> &jobs,vector<int> &dp){
        if(i==jobs.size())  return 0;

        if(dp[i]!=-1)   return dp[i];
        int next = binarySearch(jobs,i+1,jobs[i][1]);
        int take = jobs[i][2] + solve(next,jobs,dp);
        int notTake = solve(i+1,jobs,dp);
        return dp[i] = max(take,notTake);
    }
    static bool myComp(vector<int> &v1,vector<int> &v2){
        return v1[0]<v2[0];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> jobs(n,vector<int>(3,-1));
        for(int i=0;i<n;i++){
            jobs[i][0]=startTime[i];
            jobs[i][1]=endTime[i];
            jobs[i][2]=profit[i];
        }
        sort(jobs.begin(),jobs.end(),myComp);
        vector<int> dp(n,-1);
        return solve(0,jobs,dp);
    }
};
