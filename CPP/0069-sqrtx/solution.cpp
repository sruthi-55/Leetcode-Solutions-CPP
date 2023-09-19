class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(!mid || mid<=x/mid){
                ans=mid;
                l=mid+1;
            }
            else    h=mid-1;
        }
        return ans;
    }
};
