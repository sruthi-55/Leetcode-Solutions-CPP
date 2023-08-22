class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int l=0,h=n-1;
        int k=n-1;
        while(l<=h){
            if(abs(nums[l])>=abs(nums[h]))   res[k--]=nums[l]*nums[l],l++;
            else    res[k--]=nums[h]*nums[h],h--;
        }
        return res;
    }
};
