class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=nums[0];
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            //entire arr is sorted
            if(nums[l]<=nums[h]){
                ans=min(ans,nums[l]);
                break;
            }
            //right part is sorted
            if(nums[mid]<=nums[h]){
                ans=min(ans,nums[mid]);
                h=mid-1;
            }
            //left part is sorted
            else{
                ans=min(ans,nums[l]);
                l=mid+1;
            }
        }
        return ans;
    }
};
