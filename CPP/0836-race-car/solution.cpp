class Solution {
public:
    
    int racecar(int target) {
        // initial --> (position,speed) --> (0,1)
        // infinite number line
        //dp ((2^i)-1) -->[0,1,3,7,15, ]
        //i               [0,1,2,3, 4, ]
        vector<int> dp(target+1,-1);
        return helper(target,dp);
    }
    int helper(int t,vector<int> &dp){
        //to reach just after the target?
        //suppose target = 9
        // floor(log2(9))+1 = 3+1 = 4

        //so n = floor(log2(i))+1
        // steps = n + 1 + F((2^n)-1 -t)
        // steps = min(steps, n-1 +1+i+1+ F(t- (2^(n-1)-1) + (2^i)-1))
        if(dp[t]>0) return dp[t];
        int n = floor(log2(t))+1;
        if((1<<n)-1 == t)   dp[t]=n;
        else{
            dp[t] = n+1+helper((1<<n)-1-t, dp);
            for(int i=0;i<n-1;i++){
                dp[t]=min( dp[t], n-1+1+i+1+ helper(t- (1<<(n-1))-1 + (1<<i)+1 ,dp) );
            }
        }
        return dp[t];
    }
};
