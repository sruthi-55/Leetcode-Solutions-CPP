class Solution {
public:
    long long wonderfulSubstrings(string s) {
        //masking
        //traverse the string and 
        //store the xor of all letters on the fly in mask
        //       |A|B|B|A|C|C|B|
        //xor  0,[1,3,1,0,4,0,2]

        //if same mask found        ans++
        //Or if after adding one more letter, same mask is found    ans++

        //observe (A,1) and (B,1)   
        //observe (B,2)^A = 3   'cause(2^1==3)      
        long long ans=0;
        int mask=0;
        unordered_map<int,int> count;
        count[0]=1;         //imp
        for(char c:s){
            int ind=c-'a';
            mask^=(1<<ind);
            ans+=count[mask];
            for(int i=0;i<10;i++){
                int lookFor=mask^(1<<i);
                ans+=count[lookFor];
            }
            count[mask]++;
        }
        return ans;
    }
};
