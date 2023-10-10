class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zeroI=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroI=i;
                break;
            }  
        }
        if(zeroI==-1)   return;
        for(int i=zeroI+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[zeroI]);
                zeroI++;
            }  
        }
    }
};
