class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            maxi=max(maxi,nums[i]+nums[n-i-1]);
        }
        return maxi;
    }
};