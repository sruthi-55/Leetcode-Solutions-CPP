class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen=INT_MAX;
        int i=0;
        int runningSum = 0;
        for(int j=0;j<nums.size();j++){
            runningSum += nums[j];
            if(runningSum>=target){
                minLen=min(minLen,j-i+1);
                while(runningSum >= target){
                    runningSum -= nums[i];
                    i++;
                    if(runningSum>=target){
                        minLen=min(minLen,j-i+1);
                    }
                }
            }  
        }
        return minLen==INT_MAX ? 0 : minLen;
    }
};
