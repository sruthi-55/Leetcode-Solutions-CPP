class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evenC=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)   evenC++;
        }
        if(evenC>1)   return true;
        return false;
    }
};
