class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();

        int l=0,h=n-1;
        vector<int> res(n);
        int k=n-1;
        while(l<=h){
            if(abs(nums[l])<=abs(nums[h])){
                res[k--]=nums[h]*nums[h];
                h--;
            }
            else{
                res[k--]=nums[l]*nums[l];
                l++;
            }    
        }
        return res;
    }
};
