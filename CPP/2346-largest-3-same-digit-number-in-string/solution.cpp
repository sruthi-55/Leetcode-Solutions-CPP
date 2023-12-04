class Solution {
public:
    string largestGoodInteger(string num) {
        string res;
        int maxi=INT_MIN;
        for(int i=0;i<num.size();i++){
            string subStr = num.substr(i,3);
            char c1=subStr[0],c2=subStr[1],c3=subStr[2];
            if(c1==c2 && c2==c3 && maxi<stoi(subStr)){
                maxi=stoi(subStr);
                res=subStr;
            }
        }
        return res;
    }
};
