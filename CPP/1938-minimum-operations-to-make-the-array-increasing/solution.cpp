class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]){
                int op= nums[i-1]+1-nums[i];
                nums[i]=nums[i]+op;
                ans+=op;
            }
        }
        return ans;
    }
};
