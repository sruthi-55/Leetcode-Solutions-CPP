class Solution {
public:
    int minimumChairs(string s) {
        int maxC = 0;
        int count=0;
        for(char c:s){
            if(c=='E')   count++;
            else if(c=='L')  count--;
            maxC = max(maxC, count);
        }
        return maxC;
    }
};
