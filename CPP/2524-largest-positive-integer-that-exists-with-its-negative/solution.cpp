class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,h=nums.size()-1;
        while(l<h){
            if(nums[l]<0 && nums[h]>0){
                if(abs(nums[l])==abs(nums[h]))   return nums[h];
                else if(abs(nums[l])>abs(nums[h]))  l++;
                else    h--; 
            }
            else    return -1;
        }
        return -1;
    }
};
