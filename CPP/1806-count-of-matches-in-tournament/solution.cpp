class Solution {
public:
    void handleOdd(int &n,int &ans){
        ans+=(1+(n-1)/2);
        n=(n-1)/2;
    }
    void handleEven(int &n,int &ans){
        ans+=n/2;
        n=n/2;
    }
    int numberOfMatches(int n) {
        int ans=0;
        while(n!=0){
            if(n%2==0){
                handleEven(n,ans);
            }
            else{
                handleOdd(n,ans);
            }
        }
        return ans-1;
    }
};
