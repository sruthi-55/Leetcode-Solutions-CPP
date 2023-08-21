class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a=0;a*a<=c;a++){
            int b=c-(int)a*a;
            if(binary_search(0,b,b))    return true;
        }
        return false;
    }
    bool binary_search(int l,int h,int k){
        while(l<=h){
            long mid=(l+h)/2;
            if(mid*mid==k)  return true;
            else if(mid*mid>k)  h=mid-1;
            else    l=mid+1; 
        }
        return false;
    }
};

