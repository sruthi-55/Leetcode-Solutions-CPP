class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int xorr=0;
        for(int i=0;i<n;i++){
            xorr=xorr^nums[i];
        }
        xorr=xorr^k;
        
        int setBits=0;
        while(xorr!=0){
            int b=xorr%2;
            xorr/=2;
            setBits+=b;
        }
        return setBits;
    }
};
