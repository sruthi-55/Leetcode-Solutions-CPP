class Solution {
public:
    static bool myComp(int a,int b){
        int countA = countBits(a);
        int countB = countBits(b);
        return countA < countB || (countA == countB && a < b);
    }
    static int countBits(int n){
        int count=0;
        while(n!=0){
            count+= n&1;
            n= n>>1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),myComp);
        return arr;
    }
};
