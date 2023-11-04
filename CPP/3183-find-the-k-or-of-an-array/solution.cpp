class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans=0;
        for(int b=0;b<=31;b++){
            int count=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&(1<<b))  count++;
            }
            if(count>=k)    ans+=(1<<b);
        }
        return ans;
    }
};
