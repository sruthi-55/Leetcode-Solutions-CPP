class Solution {
public:
    int getSubarrays(int sum,vector<int>& arr, int m){
        int subarrays=1;
        int subArrSum=0;
        for(auto n:arr){
            if(subArrSum+n<=sum)    subArrSum+=n;
            else{
                subarrays++;
                subArrSum = n;
            }    
        }
        return subarrays;
    }
    int splitArray(vector<int>& arr, int k) {
        //same as book allocation and painters partition problem
        int n=arr.size();
        if(k>n) return -1;
        int ans=-1;
        int l=*max_element(arr.begin(),arr.end());
        int h=accumulate(arr.begin(),arr.end(),0);
        while(l<=h){
            int mid=(l+h)/2;
            if(getSubarrays(mid,arr,k)<=k){
                ans=mid;
                h=mid-1; 
            }
            else    l=mid+1;
        }
        return l;
    }
};
