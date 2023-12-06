class Solution {
public:
    int totalMoney(int n) {
        int prevMon=0;
        int curMoney=0;
        int totalMoney=0;
        for(int i=1;i<=n;i++){
            if(i%7==1){
                prevMon++;
                curMoney=prevMon;
            }
            else    curMoney++;
            totalMoney+=curMoney;
        }
        return totalMoney;
    }
};
