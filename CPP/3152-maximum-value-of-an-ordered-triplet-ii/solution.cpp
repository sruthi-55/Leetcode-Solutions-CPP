class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        if (n < 3) return 0;

        vector<long long> prefixLarge(n, 0), suffixLarge(n, 0);

        prefixLarge[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixLarge[i] = max(static_cast<long long>(nums[i]), prefixLarge[i - 1]);
        }

        suffixLarge[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixLarge[i] = max(static_cast<long long>(nums[i]), suffixLarge[i + 1]);
        }

        for (int i = 1; i < n - 1; ++i) {
            long long a = prefixLarge[i - 1];
            long long b = nums[i];
            long long c = suffixLarge[i + 1];

            long long prod = (a - b) * c;
            ans = max(ans, prod);
        }

        return ans;
    }
};

