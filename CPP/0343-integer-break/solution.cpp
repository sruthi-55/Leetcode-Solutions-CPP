class Solution {
public:
    //n=5
    //4,3,2,1   sum=5
    //pick items which sum to 5
    //Multiply value of each picked item and maximize this product
    int integerBreak(int n) {
        return dfs(n-1,n);
    }
    int dfs(int num,int sum){
        if(num==1)  return 1;
        int notPick = dfs(num-1,sum);
        int pick=0;
        if(sum>=num)   pick=num*dfs(num,sum-num);
        return max(pick,notPick);
    }
};


