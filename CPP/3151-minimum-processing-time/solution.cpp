class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.rbegin(), tasks.rend());
        sort(processorTime.begin(),processorTime.end());
        int p=processorTime.size();
        int t=tasks.size();
        
        int j=0;
        int ans=0;
        for(int i=0;i<t;i+=4){
            int sum=processorTime[j]+tasks[i];
            ans=max(ans,sum);
            j++;
        }
        
        return ans;
    }
};



  

