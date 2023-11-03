class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;
        int i=0;
        int zeroes = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0)  zeroes++;
            if(zeroes>1){
                if(nums[i]==0)  zeroes--;
                i++;
            }  
            maxLen = max(maxLen,j-i+1-1);
        }
        return maxLen;
    }
};
