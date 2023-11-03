class Solution {
public:
    bool isDivisor(string subS,string str1,string str2){
        int len=subS.size();
        int len1=str1.size(),len2=str2.size();
        if(len1%len || len2%len)    return false;

        int f1 = len1/len, f2 = len2/len;
        string resS1="",resS2="";
        for(int i=1;i<=f1;i++)  resS1+=subS;
        for(int i=1;i<=f2;i++)  resS2+=subS;

        return resS1==str1 && resS2==str2;
    }
    string gcdOfStrings(string str1, string str2) {
        int len1=str1.size(),len2=str2.size();
        for(int len=min(len1,len2);len>0;len--){
            string subS = str1.substr(0,len);
            if(isDivisor(subS,str1,str2)){
                return subS;
            }
        }
        return "";
    }
};
