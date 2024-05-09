class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end());
        int count=0;
        long long ans = 0;
        for(int i=n-1; i>=0 && k>0; i--,k--){
            ans = ans + max(0,happiness[i]-count);
            count++;
        }
        return ans;
    }
};
