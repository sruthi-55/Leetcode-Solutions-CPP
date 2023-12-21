class Solution {
public:
    int mod=1e9+7;
    int solve(int i,string &s,vector<int> &dp){
        int n = s.size();
        if(i>=n) return 1;
        if(s[i]=='0') return 0;

        if(dp[i]!=-1)   return dp[i];

        long long int ans = 0;
        if(s[i]=='1'){
            if(i==n-1)   return 1;
            else if(s[i+1]=='*'){
                ans = solve(i+1,s,dp)%mod;
                ans += (9LL * solve(i+2,s,dp)%mod)%mod;
            }    
            else{
                ans = solve(i+1,s,dp)%mod;
                ans += solve(i+2,s,dp)%mod;
            }    
        }   

        else if(s[i]=='2'){
            if(i==n-1)   return 1;
            else if(s[i+1]=='*'){
                ans = solve(i+1,s,dp)%mod;
                ans += (6LL * solve(i+2,s,dp)%mod)%mod; 
            }   
            else{
                int c = s[i+1]-'0';
                if(c>=0 && c<=6){
                    ans = solve(i+1,s,dp)%mod;
                    ans += (solve(i+2,s,dp)%mod)%mod;
                }    
                else  ans = solve(i+2,s,dp)%mod;
            }  
        }  
        else if(s[i]=='*'){
            if(i==n-1)  return 9;
            else if(s[i+1]=='*'){
                ans = 9LL * solve(i+1,s,dp)%mod;
                ans+=((1LL*9+1LL*6) * solve(i+2,s,dp)%mod)%mod;
            } 
            else{
                int c = s[i+1]-'0';
                //*1,*2....
                if(c>=0 && c<=6){
                    ans = 9LL * solve(i+1,s,dp)%mod;
                    ans += ((2LL) * solve(i+2,s,dp)%mod)%mod;
                } 
                
                else {
                    ans = (9LL * solve(i+1,s,dp)%mod)%mod;
                    ans += (1LL * solve(i+2,s,dp)%mod)%mod;
                }  
            }    
        }  
        else{
            if(i==n-1)  return 1;
            else    ans = solve(i+1,s,dp)%mod;
        }   
        return dp[i] = ans%mod;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp);
    }
};

