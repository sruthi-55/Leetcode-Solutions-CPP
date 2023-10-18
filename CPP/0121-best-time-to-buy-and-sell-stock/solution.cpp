class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minSoFar = prices[0];
        for(int i=0;i<prices.size();i++){
            int cost = prices[i] - minSoFar;
            ans = max(ans,cost);
            minSoFar = min(minSoFar,prices[i]);
        }
        return ans;
    }
};
