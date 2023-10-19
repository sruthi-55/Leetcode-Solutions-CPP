class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long op=0;
        int n=nums.size();

        long long prev=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>prev){
                //Ex: 7/3 -- (3,3,1)
                //parts= 3
                long long parts= ceil(nums[i]/(double)prev);
                //max rem as max as possible
                //equally divide number for all parts
                prev=nums[i]/parts;
                op+=parts-1;
            }
            else    prev=nums[i];
        }
        return op;
    }
};
