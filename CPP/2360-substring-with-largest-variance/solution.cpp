class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        unordered_map<char,int> freq;
        for(auto c:s)   freq[c]++;

        for(char c1='a';c1<='z';c1++){
            for(char c2='a';c2<='z';c2++){
                if(c1==c2 || freq[c1]==0 || freq[c2]==0)
                    continue;

                for(int rev=0;rev<=1;rev++){
                    int count1=0,count2=0;
                    for(auto c:s){
                        count1+= c==c1;
                        count2+= c==c2;

        //Kadane's algorithm
        //we are looking to maximize count1-count2
        //a negative value will only decrease our value
        //So why not consider new subarray by resetting count1,count2 to 0
                        if(count1<count2){
                            count1=0; count2=0;
                        }
                        if(count1>0 && count2>0)  {
                            ans=max(ans,count1-count2); 
                        } 
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};
