class Solution {
public:
    int power(char c,int k){
        int n=c-'0';
        int res=1;
        for(int i=0;i<k;i++)   res=res*10;
        return n*res;
    }
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int count=0;

        int i=0;
        int no=0;
        for(int j=0;j<s.size();j++){
            no=no*10+(s[j]-'0');
            if(j-i+1==k){
                if(no!=0 && num%no==0)    count++;
                no-=power(s[i],k-1);
                i++;
            }   
        }
        return count;
    }
};



