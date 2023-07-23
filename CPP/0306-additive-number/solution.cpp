class Solution {
public:
    bool isAdditiveNumber(string num) {
        // i and j represent size of two substrings that need to be added
        // i: 1 --> n/2
        // j: 1 --> (n-i)/2
        int n=num.size();
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=(n-i)/2;j++){
                string first=num.substr(0,i);
                string second=num.substr(i,j);
                string rem=num.substr(i+j);
                if(check(first,second,rem)) return true;
            }
        }
        return false;
    }
    bool check(string first,string second,string rem){
        if((first.size()>1 && first[0]=='0') 
            || (second.size()>1 && second[0]=='0'))   return false;
        string sum = to_string(stol(first) + stol(second));
        if(rem==sum)    return true;
        if(rem.size()<sum.size() || sum.compare(rem.substr(0,sum.size()))!=0)
            return false;
        //if we reach here then we have a match until sum.size() 
        //so we need to continue checking for the rest of the string
        else    return check(second,sum,rem.substr(sum.size()));
    }
};
