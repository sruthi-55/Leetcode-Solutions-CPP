class Solution {
public:
    bool isPossible(int maxi,vector<long> nums){
        if(nums[0]>maxi)   return false;

        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]<=maxi)   continue;
            else{
                long diff = nums[i]-maxi;
                nums[i-1]+=diff;
            }
        }
        if(nums[0]>maxi)    return false;
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int l=0,h=*max_element(nums.begin(),nums.end());
        vector<long> vec(nums.begin(),nums.end());
        while(l<=h){
            int mid =(l+h)/2;
            if(isPossible(mid,vec)){
                ans=mid;
                h=mid-1;
            }
            else    l=mid+1;
        }
        return ans;
    }
};
