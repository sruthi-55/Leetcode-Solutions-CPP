class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curP = arr[0], winC = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>curP){
                curP = arr[i];
                winC = 0;
            }
            winC++;
            if(winC==k) break;
            
        }
        return curP;
    }
};
