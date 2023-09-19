class Solution {
public:
    //get no. of days required to ship all packages 
    //if max capacity of ship is k
    int getDays(int k,vector<int> &weights){
        int totalDays=1;
        int load=0;
        for(auto w: weights){
            if(load+w<=k) load+=w;
            else{
                load=w;
                totalDays++;
            }
        }
        return totalDays;
    }
    int shipWithinDays(vector<int>& weights, int threshold) {
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);
        int ans=h;
        while(l<=h){
            int mid=(l+h)/2;
            if(getDays(mid,weights)<=threshold){
                ans=mid;
                h=mid-1;
            }
            else    l=mid+1;
        }
        return ans;
    }
};
