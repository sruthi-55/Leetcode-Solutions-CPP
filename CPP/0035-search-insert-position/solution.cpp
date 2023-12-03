class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //need to find index of ele >=target
        //lower bound
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    }
};
