class Solution {
public:
    long long timeToEat(int k,vector<int> &piles){
        long long totalTime=0;
        for(auto bananas: piles){
            totalTime += ceil((double)bananas/(double)k);
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int threshold) {
        int l=1,h=*max_element(piles.begin(),piles.end());
        int ans=h;
        while(l<=h){
            int mid=(l+h)/2;
            if(timeToEat(mid,piles)<=threshold){
                ans=mid;
                h=mid-1;
            }
            else    l=mid+1;
        }
        return ans;
    }
};
