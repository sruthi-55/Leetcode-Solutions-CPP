class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)    return 1;
        if(n==1)    return 10;
        if(n==2)    return 10+9*9;

        int prod = 9*9;
        int ans=10+9*9;
        for(int i=3;i<=n;i++){
            prod *= (9-(i-2));
            ans+=prod;
        }
        return ans;
    }
};
