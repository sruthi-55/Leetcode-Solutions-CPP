class Solution {
public:
    //check if possible to make m boquets
    //k adjacent flowers
    bool isPossible(int day,vector<int>& bloomDay, int m, int k){
        int boquets=0;
        int countAdj=0;
        for(auto bloomD : bloomDay){
            if(bloomD<=day)  countAdj++;
            else{
                boquets+= (countAdj/k);
                countAdj=0;
                if(boquets>=m)  return true;
            }
        }
        boquets+= (countAdj/k);
        if(boquets>=m)  return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(isPossible(mid,bloomDay,m,k)){
                ans=mid;
                h=mid-1;
            }
            else    l=mid+1;
        }
        return ans;
    }
};
