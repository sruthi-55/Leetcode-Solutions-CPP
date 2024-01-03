class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size(),m=bank[0].size();
        int ans=0;
        int prev=-1,cur=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1') count++;
            }
            if(i==0)    prev=count;
            else{
                if(count!=0){
                    cur=count;  
                    ans+=prev*cur;
                    prev=cur;
                }  
            }    
        }
        return ans;
    }
};
