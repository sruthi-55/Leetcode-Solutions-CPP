class Solution {
public:
    void sortColors(vector<int>& arr) {
        //Dutch national flag algorithm
        //000....000,111....111,A[0],A[1],......A[n-1],222.....222
        //zeroes - (0,l-1)
        //ones - (l,mid-1)
        //array - (mid,h)
        //twos - (h+1,n-1)
        int l=0,mid=0,h=arr.size()-1;
        while(mid<=h){
            if(arr[mid]==0){
                swap(arr[l],arr[mid]);
                mid++;  l++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else {
                swap(arr[mid],arr[h]);
                h--;
            }
        }
    }
};
