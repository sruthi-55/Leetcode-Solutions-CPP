class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n=s.length();

        int label[n];
        for(int i=0;i<n;i++){
            if(s[i]=='A')   label[i]=0; //00
            else if(s[i]=='T')  label[i]=1; //01
            else if(s[i]=='G')  label[i]=2; //10
            else    label[i]=3; //11
        }

        long long int hash_val=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n-9;i++){
            if(i==0){
                for(int i=0;i<10;i++){
                    hash_val= (hash_val<<2) + label[i]; //converting to decimal number  
                }
                mp[hash_val]++;
            }
            else{
                // Finding new hash value 
                hash_val = (hash_val<<2) - (label[i - 1]<<20) + label[i + 9]; 
                mp[hash_val]++;
                if(mp[hash_val]==2){
                    res.push_back(s.substr(i,10));
                }
            }
        }
        return res;
    }
};
