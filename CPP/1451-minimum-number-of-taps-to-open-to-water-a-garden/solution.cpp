class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int ans=0;

        //from starting at each tap, array stores the max right coordinate 
        vector<int> tapRange(n+1,0);
        for(int i=0;i<ranges.size();i++){
            int left=max(0,i-ranges[i]);
            tapRange[left]=max(tapRange[left],i+ranges[i]);
        }

        //spread
        int end=0,farCanReach=0;
        for(int i=0;i<ranges.size();i++){
            end=farCanReach;
            if(end>=n)  return ans;

            //add another tap which starts within end and spreads max
            ans++;
            while(i<n+1 && i<=end){
                farCanReach = max(farCanReach,tapRange[i]);
                i++;
            }
            i--;  
            //if even after adding tap, farCanReach is not increasing 
            //then there is discontinuity and hence not possible
            if(end==farCanReach)    return -1;
        }
        return ans;
    }
};
