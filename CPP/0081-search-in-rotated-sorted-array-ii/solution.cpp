class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int l=0,h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==target)   return true;
            if(arr[l]==arr[mid] && arr[h]==arr[mid]){
                l++,h--;
                continue;
            }
            //left part is sorted
            else if(arr[l]<=arr[mid]){
                if(arr[l]<=target && target<=arr[mid])    h=mid-1;
                else    l=mid+1;
            }
            //right part is sorted
            else{
                if(arr[mid]<=target && target<=arr[h])    l=mid+1;
                else    h=mid-1;
            }
        }
        return false;
    }
};

