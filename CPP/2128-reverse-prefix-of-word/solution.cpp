class Solution {
public:
    void reverse(string &word,int s,int e){
        while(s<=e){
            char temp=word[s];
            word[s]=word[e];
            word[e]=temp;
            s++;
            e--;
        }
    }
    string reversePrefix(string word, char ch) {
        int n=word.size();
        int ind = -1;
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                ind = i;
                break;
            }  
        }
        if(ind==-1) return word;
        reverse(word,0,ind);
        return word;
    }
};
