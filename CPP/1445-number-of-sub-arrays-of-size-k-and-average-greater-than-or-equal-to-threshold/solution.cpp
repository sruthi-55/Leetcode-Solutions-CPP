class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans=0;
        int n=arr.size();

        int i=0;
        int sum=0;
        int average=0;
        for(int j=0;j<n;j++){
            sum+=arr[j];
            if(j-i+1==k){
                average = (double)sum/k;
                sum-=arr[i];
                i++;
                if(average>=threshold)  ans++;
            }
        }
        return ans;
    }
};
