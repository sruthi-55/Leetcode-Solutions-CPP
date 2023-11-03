class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        if(n==0)    return true;
        for(int i=0;i<nums.size();){
            if(nums[i]==1){
                i+=2;
            }
            else{
                if((i==0 && (i<nums.size()-1 && nums[i+1]==0)) 
                || i+1==nums.size() || nums[i+1]==0){
                    n--;i+=2;
                }    
                else{
                    i+=3;
                }
            }
            if(n==0)    return true;
        }
        return false;
    }
};
