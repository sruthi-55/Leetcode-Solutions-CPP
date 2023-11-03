class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int op=0;
        int l=0,h=nums.size()-1;
        while(l<h){
            if(nums[l]+nums[h]==k)  op++,l++,h--;
            else if(nums[l]+nums[h]<k)  l++;
            else    h--;
        }
        return op;
    }
};
