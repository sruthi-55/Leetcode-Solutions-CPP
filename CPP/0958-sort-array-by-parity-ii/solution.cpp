class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        int e=0,o=1;
        while(e<n && o<n){
            while(e<n && nums[e]%2==0)  e+=2;
            while(o<n && nums[o]%2==1)  o+=2;
            if(e<n && o<n){
                int temp=nums[e];
                nums[e]=nums[o];
                nums[o]=temp;
                e+=2;o+=2;
            }
        }
        return nums;
    }
};
