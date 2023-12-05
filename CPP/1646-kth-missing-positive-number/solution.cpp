class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]-mid <= k){
                l=mid+1;
            }
            else    h=mid-1;
        }
        return k+h+1;
    }
};
