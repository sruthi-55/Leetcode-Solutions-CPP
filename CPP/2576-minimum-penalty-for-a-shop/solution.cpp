class Solution {
public:
    int bestClosingTime(string customers) {
        int hour=0;
        int minPenalty=INT_MAX;
        int n=customers.size();
        
        //no. of hours shop(closed) has no customers before ith hour
        vector<int> prefixNO;
        prefixNO.push_back(0);
        int nos=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='N') nos++;
            prefixNO.push_back(nos);
        }

        //no. of hours shop(closed) has customers from ith hour 
        vector<int> suffixYES;
        suffixYES.push_back(0);
        int yess=0;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y')   yess++;
            suffixYES.push_back(yess);
        }
        reverse(suffixYES.begin(),suffixYES.end());

        for(int i=0;i<n+1;i++){
            if(minPenalty>prefixNO[i]+suffixYES[i]){
                minPenalty=prefixNO[i]+suffixYES[i];
                hour=i;
            }
        }

        return hour;
    }
};
