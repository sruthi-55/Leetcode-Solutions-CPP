class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats=0;
        sort(people.begin(),people.end());
        int l=0,h=people.size()-1;
        while(l<=h){
            if(people[l]+people[h]<=limit){
                boats++;
                l++;h--;
            }  
            else{
                boats++;
                h--;
            }
        }
        return boats;
    }
};
