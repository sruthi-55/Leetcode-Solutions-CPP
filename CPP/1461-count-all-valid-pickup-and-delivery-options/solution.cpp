class Solution {
public:
    int mod = 1e9+7;
    int countOrders(int n) {
        if(n==1)    return 1;
        long long count = 1;
        for(int i=2;i<=n;i++){
            int spaces = 2*(i-1)+1;
            int ways = spaces*(spaces+1)/2;
            count = (count * ways)%mod;
        }
        return count%mod;
    }
};
