class Solution {
public:
    int mySqrt(int x) {
        return bs(0,x,x);
    }
    int bs(int low,int high,int target){
        int ans = -1;
        while(low<=high){
            long mid = low + (high - low)/2;
            if(mid*mid==target){
                ans=mid;
                break;
            }
            else if(mid*mid<target){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};
