class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<h){
            if(nums[h]%2==0)    swap(nums[l++],nums[h]);
            else    h--;
        }
        return nums;
    }
};
