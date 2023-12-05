class Solution {
public:
    bool binarySearch(vector<int> &nums,int target){
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target)   return true;
            else if(nums[mid]>target)   h=mid-1;
            else    l=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && target<=matrix[i][m-1])
                return binarySearch(matrix[i],target);
        }
        return false;
    }
};
