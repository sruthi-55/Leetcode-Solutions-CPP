class Solution {
public:
    int minOperations(string s) {
        int zeroFirst=0,oneFirst=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]!='0')   zeroFirst++;
                else    oneFirst++;
            }  
            else{
                if(s[i]!='1')   zeroFirst++;
                else    oneFirst++;
            }
        }
        return min(zeroFirst,oneFirst);
    }
};
