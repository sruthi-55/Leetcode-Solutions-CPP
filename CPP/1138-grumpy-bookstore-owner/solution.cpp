class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();

        //fixed size sliding window of size 'minutes'
        int i=0;
        int j=0;
        int maxUnsat = 0;
        int curUnsat = 0;
        while(j<n){
            while(j<n && j<minutes){      // < window size => make window
                curUnsat += customers[j] * grumpy[j];
                j++;
                maxUnsat = max(maxUnsat, curUnsat);
            }    
            if(j>=n)    break;

            curUnsat -= customers[i] * grumpy[i];
            curUnsat += customers[j] * grumpy[j];
            i++;
            j++;
            maxUnsat = max(maxUnsat, curUnsat);
        }

        
        int satisfiedCust = 0;
        for(int i=0;i<n;i++){
            satisfiedCust += customers[i] * (1 - grumpy[i]);  
        }
        return satisfiedCust + maxUnsat; //(secret technique of book store owner)
    }
};
