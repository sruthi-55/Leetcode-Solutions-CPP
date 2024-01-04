class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int n:nums) map[n]++;
        
        int op=0;
        for(auto it:map){
            int occ=it.second;
            if(occ==1)  return -1;
            else if(occ%3==0)   op+=occ/3;
            else if(occ%3==1)   op+=(1+occ/3);
            else if(occ%3==2)   op+=(1+occ/3);
        }
        return op;
    }
};
