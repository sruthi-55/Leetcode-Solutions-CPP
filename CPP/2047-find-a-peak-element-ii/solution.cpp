class Solution {
public:
    int getMaxIndCol(vector<vector<int>>& mat,int col){
        int maxi = INT_MIN;
        int maxInd = -1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>maxi){
                maxi = mat[i][col];
                maxInd = i;
            }
        }
        return maxInd;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int l = 0, h = m-1;
        while(l<=h){
            int mid = (l+h)/2;

            int maxR = getMaxIndCol(mat,mid);

            int left = mid-1>=0 ? mat[maxR][mid-1] : -1;
            int right = mid+1<m ? mat[maxR][mid+1] : -1;
            
            if(mat[maxR][mid]>left && mat[maxR][mid]>right)    
                return {maxR,mid};
            else if(mat[maxR][mid] < left)  h=mid-1;
            else    l=mid+1;
        }
        return {-1,-1};
    }
};
