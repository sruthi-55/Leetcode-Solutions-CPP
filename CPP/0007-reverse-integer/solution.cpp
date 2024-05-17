#define intt long long int
class Solution {
public:
    int reverse(int x) {
        int num = x;
        intt revNum = 0;
        
        while(num){
            int d = num%10;
            revNum = revNum * 10 + d;
            num = num/10;
        }
        if(revNum <= INT_MIN || revNum >= INT_MAX)    return 0; 
        return revNum;
    }
};
