class Solution {
public:
    string sortString(string str, string res="") {
        //"aaaabbbbcccc"
        //a=4, b=4, c=4
        //abc cba abc cba
        int freq[26]={0};
        for(char c:str)
            freq[c-'a']++;
        while(str.size()!=res.size()){
            for(int i=0;i<26;i++){
                if(--freq[i]>=0)
                res+= 'a'+i;
            }
            for(int i=25;i>=0;i--){
                if(--freq[i]>=0)
                res+= 'a'+i;
            }  
        }
        return res;
    }
};
