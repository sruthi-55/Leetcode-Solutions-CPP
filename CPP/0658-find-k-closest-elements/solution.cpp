class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int l=0,h=arr.size()-k;
        while(l<h){
            int mid=(l+h)/2;
            if(x-arr[mid]<=arr[mid+k]-x) {
                h=mid;
            }
            else    l=mid+1;
        }
        for(int i=0;i<k;i++)
            res.push_back(arr[h+i]);
        return res;
    }
};
