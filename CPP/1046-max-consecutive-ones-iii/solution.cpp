class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int i=0;
        int zeroes=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0)  zeroes++;
            while(zeroes>k){
                if(nums[i]==0)  zeroes--;
                i++;
            }
            maxLen = max(maxLen,j-i+1);
        }
        return maxLen;
    }
};
