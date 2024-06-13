class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n=seats.size();
        vector<int> seatPos(101,0),studPos(101,0);
        for(auto s:seats)   seatPos[s]++;
        for(auto s:students)    studPos[s]++;

        int seat=0,stud=0;
        int res=0;
        while(seat<=100 && stud<=100){
            if(seatPos[seat]==0)    seat++;
            if(studPos[stud]==0)    stud++;

            if(seat<=100 && stud<=100 && seatPos[seat]!=0 && studPos[stud]!=0){
                res += abs(seat-stud);
                seatPos[seat]--;
                studPos[stud]--;
            }
        }
        return res;
    }
};
