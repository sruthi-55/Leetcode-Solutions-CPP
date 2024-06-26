class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long num=n;
        //if index is -ve, make it positive
        if(num<0) num=-1*num;
        while(num>0){
            if(num%2==0){
                x=x*x;
                num=num/2;
            }
            else{
                ans=ans*x;
                num--;
            }
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};
