class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int ind1 = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(ind1>=nums.size() || nums[ind1]!=target)   return {-1,-1};
        res.push_back(ind1);

        int ind2 = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        res.push_back(ind2-1);
        return res;
    }
};
