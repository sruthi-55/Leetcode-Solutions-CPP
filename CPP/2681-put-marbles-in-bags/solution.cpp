class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> conSum;
        //consecutive sum
        for(int i=0;i<n-1;i++){
            int sum=weights[i]+weights[i+1];
            conSum.push_back(sum);
        }
        sort(conSum.begin(),conSum.end());

        //need to get first k-1 pairs and last k-1 pairs
        long long maxSum=0, minSum=0;
        for(int i=0;i<=k-2;i++){
            minSum+=conSum[i];
            maxSum+=conSum[n-2-i];
        }
        
        return maxSum-minSum;
    }
};
