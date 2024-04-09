class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        while(true){
            for(int i=0;i<tickets.size();i++){
                if(tickets[i]>0){
                    tickets[i]--;
                    time++;
                    if(i==k && tickets[k]==0)   return time;
                }    
                else    continue;
            }
        }
        return -1;
    }
};
