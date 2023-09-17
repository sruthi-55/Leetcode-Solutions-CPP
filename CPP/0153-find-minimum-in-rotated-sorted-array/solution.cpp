class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=1e9;
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[l]<=nums[h]){
                ans=min(ans,nums[l]);
                break;
            }   
            //left part is sorted
            if(nums[l]<=nums[mid]){
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            //right part is sorted
            else if(nums[mid]<=nums[h]){
                ans=min(ans,nums[mid]);
                h=mid-1;
            }
        }
        return ans;
    }
};
