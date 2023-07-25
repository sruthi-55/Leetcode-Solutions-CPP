class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=0;
        int s=0,e=arr.size()-1;
        while(s<e){
            int mid=(s+e)/2;
            if(arr[mid]<arr[mid+1]){
                ans=mid+1;
                s=mid+1;
            } 
            else
                e=mid;
        }
        return ans;
    }
};
