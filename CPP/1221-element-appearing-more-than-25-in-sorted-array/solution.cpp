class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int quarter=n/4;
        int maxEle = arr[0];
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==maxEle)  count++;
            else    count=1;
            if(count>quarter)
                return maxEle;
            maxEle = arr[i];
                
        }
        return maxEle;
    }
};
