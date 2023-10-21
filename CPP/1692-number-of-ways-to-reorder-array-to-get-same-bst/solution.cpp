class Solution {
public:
    long long mod=1e9+7;
    long long dfs(vector<int>& nums,vector<vector<long long>> &nCr){
        int n=nums.size();
        if(n<=2)   return 1;

        vector<int> left,right;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[0]) left.push_back(nums[i]);
            else    right.push_back(nums[i]);
        }

        long long left_ways = dfs(left,nCr)%mod;
        long long right_ways = dfs(right,nCr)%mod;
        return (((nCr[n-1][left.size()] * left_ways)%mod) * right_ways)%mod;
    }
    int numOfWays(vector<int>& nums) {
        vector<vector<long long>> nCr(nums.size()+1);

        for(int i=0;i<=nums.size();i++){
            nCr[i] = vector<long long>(i+1,1);
            for(int j=1;j<i;j++){
                nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j])%mod;
            }
        }
        return dfs(nums,nCr)%mod-1 ;
    }
};
