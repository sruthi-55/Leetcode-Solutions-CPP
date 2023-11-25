class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();

        vector<int> prefixSum;
        int pSum=0;
        for(int i=0;i<n;i++){
            pSum+=nums[i];
            prefixSum.push_back(pSum);
        }
        
        for(int i=0;i<n;i++){
            int leftSum = prefixSum[i]-nums[i];
            int rightSum = prefixSum[n-1] - leftSum;
            int value = (i+1)*nums[i]-leftSum + rightSum-nums[i]*(n-i+1);
            res.push_back(value);
        }
        return res;
    }
};
