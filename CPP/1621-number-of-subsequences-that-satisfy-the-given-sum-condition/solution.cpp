class Solution {
public:
    typedef long long ll;
    ll myPow(ll x, ll n) {
        ll ans=1;
        ll num=n;
        while(num>0){
            if(num%2==0){
                x=(x*x)%mod;
                num=num/2;
            }
            else{
                ans=(ans*x)%mod;
                num--;
            }
        }
        return ans;
    }

    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;

        sort(nums.begin(),nums.end());
        
        int l=0,h=nums.size()-1;
        while(l<=h){
            if(nums[l]+nums[h]<=target){
                int diff = h-l;
                ans = (ans + myPow(2,diff)%mod)%mod;
                l++;
            }
            else    h--;
        }
        return ans%mod;
    }
};



