class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<h){
            while(l<h && nums[l]%2==0) l++;
            while(l<h && nums[h]%2==1) h--;
            int temp = nums[l];
            nums[l]=nums[h];
            nums[h]=temp;
            l++;h--;
        }
        return nums;
    }
};
