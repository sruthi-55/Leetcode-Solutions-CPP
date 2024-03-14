class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> prefixSum;
        
        int count   = 0;
        int currSum = 0;
        prefixSum[0] = 1;
        for(int &num : nums) {
            currSum += num;
            int req = currSum - goal;
            if(prefixSum.find(req) != prefixSum.end()) {
                count += prefixSum[req];
            }
            
            prefixSum[currSum]++;
        }
        return count;
    }
};

