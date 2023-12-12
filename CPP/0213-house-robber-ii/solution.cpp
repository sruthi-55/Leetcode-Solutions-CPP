class Solution {
public:
    int robLinear(vector<int>& nums) {
        int n=nums.size();
        int prev2=0;
        int prev1=nums[0];

        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>=2)    pick+=prev2;
            int notPick = prev1;
            int cur = max(pick,notPick);

            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0)    temp1.push_back(nums[i]);
            if(i!=nums.size()-1)  temp2.push_back(nums[i]);
        }
        
        int excludingFirst = robLinear(temp1);
        int excludingLast = robLinear(temp2);
        return max(excludingFirst,excludingLast);
    }
};
