class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int maxi=0;
        //i --> represent end of substr.  Loop from 0-n
        //j --> represent start of substr
        int ch[26]={0};
        int letters=0;  //no. of unique letters
        unordered_map<string,int> m;
        int j=0;
        for(int i=0;i<s.length();i++){
            if(ch[s[i]-'a']++==0)   letters++;
            //moving j
            while(letters>maxLetters || i-j+1>maxSize){
                if(--ch[s[j]-'a']==0)   letters--;
                j++;
            }
            while(i-j+1>=minSize){
                string cur=s.substr(j,i-j+1);
                m[cur]++;
                maxi=max(maxi,m[cur]);
                //check for substrings in between 
                if(--ch[s[j]-'a']==0)   letters--;
                j++;
            }
        } 
        return maxi;  
    }
};
