class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,-1));
        int left=0,right=n-1;
        int top=0,bottom=n-1;
        
        int count=1;
        while(count<=n*n){
            for(int i=left; i<=right && count<=n*n; i++)    ans[top][i]=count++;
            for(int i=top+1; i<=bottom-1 && count<=n*n; i++)    ans[i][right]=count++;
            for(int i=right; i>=left && count<=n*n; i--)    ans[bottom][i]=count++;
            for(int i=bottom-1; i>=top+1 && count<=n*n; i--)    ans[i][left]=count++;
            left++;right--;top++;bottom--;
        }
        return ans;
    }
};
