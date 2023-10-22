class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0)    return 1.0;
        if(k-1+maxPts <=n)  return 1.0;

        //getting 10 = from 9 getting 1 + from 8 getting 2 +.... + from 0 getting 10
        //P(10) = (1/10)P(9) + (1/10)P(8) + .... + (1/10)P(1) + (1/10)P(0)
        //dp[i] = (1/maxPts)(dp[i-1]+dp[i-2]+.... dp(i-maxPts))

        vector<double> dp(n+1,0.0);
        dp[0]=1.0;
        double windowSum = 1.0;
        double probability = 0.0;
        for(int i=1;i<=n;i++){
            //winodwSum until prev / maxPts
            dp[i] = windowSum/maxPts;
            if(i<k) windowSum+=dp[i];
            else    probability+=dp[i];

            if(i>=maxPts)    windowSum-=dp[i-maxPts];
            
        }
        return probability;
    }
};
