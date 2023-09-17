class Solution {
public:
    int bS(int l,int h,vector<int> &nums,int target){
        if(l>h) return -1;
        int mid=(l+h)/2;
        if(nums[mid]==target)   return mid;
        else if(nums[mid]>target)   return bS(l,mid-1,nums,target);
        return bS(mid+1,h,nums,target);
    }
    int search(vector<int>& nums, int target) {
        return bS(0,nums.size()-1,nums,target);
    }
};
