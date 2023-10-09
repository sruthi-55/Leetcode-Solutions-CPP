class Solution {
public:
    int findFirst(vector<int>& arr, int n, int k){
        int ans=-1;
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==k){
                ans=mid;
                h=mid-1;
            }   
            else if(arr[mid]>k) h=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    int findLast(vector<int>& arr, int n, int k){
        int ans=-1;
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]<=k){
                ans=mid;
                l=mid+1;
            }
            else if(arr[mid]>k) h=mid-1;
            else    l=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int first = findFirst(nums,nums.size(),target);
        if(first == -1)     return {-1,-1};
        int last = findLast(nums,nums.size(),target);
        return {first,last};
    }
};
