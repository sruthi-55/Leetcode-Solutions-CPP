class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        unordered_map<int,int> prefixSum;
        int sum=0;
        prefixSum[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int required = sum-k;
            if(prefixSum.find(required)!=prefixSum.end()){
                count+=prefixSum[required];
            }
            prefixSum[sum]++;
        }
        return count;
    }
};
