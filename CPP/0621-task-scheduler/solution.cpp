class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans=0;
        unordered_map<char,int> mp;
        for(char task: tasks)
            mp[task]++;

        priority_queue<int> pq;
        for(auto it : mp) {
            pq.push(it.second);
        }

        while(!pq.empty()){
            vector<int> doneTasks;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    //Pick task with max freq
                    int maxFreq = pq.top(); 
                    pq.pop();
                    //do it
                    //reduce freq
                    doneTasks.push_back(maxFreq-1);
                }
            }

            //update progress of done tasks 
            //if another occurrence is still present add it queue
            for(int freq:doneTasks){
                if(freq>0)
                    pq.push(freq);
            }

            if(!pq.empty())
                ans+=n+1;
            else    ans+=doneTasks.size();
        }
        return ans;
    }
};
