class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(target==nums[mid])   return mid;
            //right part is sorted
            else if(nums[mid]<=nums[h]){
                if(nums[mid]<=target && target<=nums[h])    l=mid+1;
                else    h=mid-1;
            }
            //left part is sorted
            else{
                if(nums[l]<=target && target<=nums[mid])    h=mid-1;
                else    l=mid+1;
            }
        }
        return -1;
    }
};
