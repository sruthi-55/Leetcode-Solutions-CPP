class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int n=cardPoints.size();
        int totalSum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(k==n)    return totalSum;

        int i=0;
        int points=0;
        for(int j=0;j<n;j++){
            points+=cardPoints[j];
            if(j-i+1==n-k){
                ans=max(ans,totalSum-points);
                points-=cardPoints[i];
                i++;
            }
        }
        return ans;
    }
};
