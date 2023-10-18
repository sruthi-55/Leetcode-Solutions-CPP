class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        int pos=0,neg=1;
        for(int i=0;i<n;i++){
            //positive
            if(nums[i]>0){
                res[pos]=nums[i];
                pos+=2;
            }
            //negative
            else{
                res[neg]=nums[i];
                neg+=2;
            }
        }
        return res;
    }
};
