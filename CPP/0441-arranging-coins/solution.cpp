class Solution {
public:
    int arrangeCoins(int n) {
        int ans=1;
        int l=0,h=n;
        while(l<=h){
            long mid=l+(h-l)/2;
            if(mid*(mid+1)/2 == n)  return mid;
            else if(mid*(mid+1)/2 < n){
                ans=mid;
                l=mid+1;
            }
            else    h=mid-1;
        }
        return ans;
    }
};
