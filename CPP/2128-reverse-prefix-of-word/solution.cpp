class Solution {
public:
    void reverse(string &word,int ind){
        int l=0,h=ind;
        while(l<h){
            int temp=word[l];
            word[l]=word[h];
            word[h]=temp;
            l++;h--;
        }
    }
    string reversePrefix(string word, char ch) {
        int ind=-1;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                ind=i;break;
            }
        }
        if(ind!=-1)
            reverse(word,ind);
        return word;
    }
};
