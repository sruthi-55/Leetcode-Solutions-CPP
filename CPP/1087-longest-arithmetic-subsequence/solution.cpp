class Solution {
public:
    int longestArithSeqLength(std::vector<int>& nums) {
        int n = nums.size();
        if(n==2)    return 2;

        vector<unordered_map<int, int>> dp(n);
        int result = 2;  
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                int length = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                dp[i][diff] = max(dp[i][diff], length);

                result = max(result, length);
            }
        }
        return result;
    }
};

