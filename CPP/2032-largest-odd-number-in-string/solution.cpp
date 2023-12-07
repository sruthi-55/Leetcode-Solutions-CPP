class Solution {
public:
    string largestOddNumber(string nums) {
        int lastOddIndex=-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]%2==0)    continue;
            else{
                lastOddIndex = i;
                break;
            }
        }
        return nums.substr(0,lastOddIndex+1);
    }
};
