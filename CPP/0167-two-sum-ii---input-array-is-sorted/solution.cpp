class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            if(nums[l]+nums[h]==target) return {l+1,h+1};
            else if(nums[l]+nums[h] < target)   l++;
            else h--;
        }
        return {};
    }
};
