class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int lastSpaceInd = -1;
        int j=n-1;
        while(s[j]==' ')    j--;
        for(int i=j;i>=0;i--){
            if(s[i]==' '){
                lastSpaceInd = i;
                break;
            }
        }
        return j-lastSpaceInd;
    }
};
