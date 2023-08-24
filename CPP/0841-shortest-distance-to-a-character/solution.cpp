class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        //minimum of distances from either side
        vector<int> ans;

        //max value that result vector elements can have is n-1
        //to ignore left check we place it at very low index
        int prev=-n;
        for(int i=0;i<n;i++){
            if(s[i]==c)   prev=i;
            ans.push_back(i-prev);
        }
        //to ignore right check we place it at a very high index
        int next=2*n;
        for(int i=n-1;i>=0;i--){
            if(s[i]==c)   next=i;
            ans[i]=min(ans[i],next-i);
        }
        return ans;
    }

    // l,o,v,e,l,e,e,t,c,o,d,e       //c='e'
    //left pass
    //[H,H,H,0,1,0,0,1,2,3,4,0]
    //right pass
    //[3,2,1,0,1,0,0,1,2,2,1,0]

    // a,b,a,a          //c='b'
    //left pass
    //[H,0,1,2]
    //[1,0,1,2]
};
