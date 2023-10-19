class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n+1,0);
        //arr[left] = right;
        //from starting at each left coordinate, arr stores the max right coordinate
        for(int i=0;i<ranges.size();i++){
            int left = max(0,i-ranges[i]);
            arr[left] = max(arr[left],i+ranges[i]);
        }

        int taps=0;
        int end=0;
        int maxCanReach=0;
        //spread
        for(int i=0;i<ranges.size();i++){
            end=maxCanReach;
            if(end>=n)  return taps;

            taps++;
            //consider max range of taps before previous end and compute maxCanReach
            while(i<n+1 && i<=end){
                maxCanReach = max(maxCanReach,arr[i]);
                i++;
            }
            i--;
            ////if even after adding tap, maxCanReach is not increasing 
            //then there is discontinuity and hence not possible
            if(maxCanReach==end)    return -1;
        }
        return taps;
    }
};
