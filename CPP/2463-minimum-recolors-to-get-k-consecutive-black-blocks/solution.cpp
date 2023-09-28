class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;

        int i=0;
        int whites=0;
        for(int j=0;j<blocks.size();j++){
            if(blocks[j]=='W')   whites++;
            if(j-i+1==k){
                ans=min(ans,whites);
                if(blocks[i]=='W')  whites--;
                i++;
            }
        }
        return ans;
    }
};




