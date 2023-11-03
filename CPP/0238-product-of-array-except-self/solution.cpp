class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int prod=1;
        int zeroCount = 0;
        for(auto ele:nums){
            if(ele==0){
                zeroCount++;
                continue;
            }  
            else{
                prod = prod*ele;
            }
        }
        if(zeroCount==nums.size())    prod = 0;
          

        if(zeroCount){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    //only 1 zero
                    if(zeroCount==1)    res[i]=prod;  
                } 
            }
        } 
        else{
            for(int i=0;i<nums.size();i++){
                res[i] = prod/nums[i];    
            }     
        }    
        
        return res;
    }
};
