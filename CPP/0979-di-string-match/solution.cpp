class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        int l=0,h=n;
        vector<int> res(n+1);
        for(int i=0;i<=n;i++){
            if(s[i]=='I')   res[i]=l++;
            else    res[i]=h--;
        }
        s[n]=='I' ? res[n]=h : res[n]=l;
        return res;

        //IDID
        //res -- [0,4,1,3,l]

        //III
        //res -- [0,1,2,h]

        //DDI
        //res -- [3,2,0,h]
    }
};
