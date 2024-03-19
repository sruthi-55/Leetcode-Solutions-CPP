class Solution {
public:
    bool isPerfectSquare(int num) {
        return bs(0,num,num);
    }
    bool bs(int low,int high,int target){
        while(low<=high){
            long mid=low+(high-low)/2;
            if(mid*mid==target) return true;
            else if(mid*mid<target) low=mid+1;
            else    high=mid-1;
        }
        return false;
    }
};
