class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans=0; long sum=0;
        sort(nums.begin(),nums.end());
        int l=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum+k<(long)nums[r]*(r-l+1))
                sum-=nums[l++];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
