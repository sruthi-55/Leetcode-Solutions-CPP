class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k;
        int j = k;
        int curMin = nums[k];
        int res = nums[k];
        
        while (i > 0 || j < n - 1) {
            int leftValue = (i > 0) ? nums[i - 1] : 0;
            int rightValue = (j < n - 1) ? nums[j + 1] : 0;

            if (leftValue < rightValue) {
                j++;
                curMin = min(curMin, nums[j]);
            } 
            else {
                i--;
                curMin = min(curMin, nums[i]);
            }
            res = max(res, curMin * (j - i + 1));
        }
        
        return res;
    }
};


