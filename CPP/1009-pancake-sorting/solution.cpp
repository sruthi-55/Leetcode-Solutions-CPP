class Solution {
public:
    void flip(vector<int> &arr,int ind){
        int l=0,h=ind;
        while(l<h){
            int temp=arr[l];
            arr[l]=arr[h];
            arr[h]=temp;
            l++;h--;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n=arr.size();
        for(int i=n-1;i>0;i--){
            for(int j=1;j<=i;j++){
                if(arr[j]==i+1){
                    flip(arr,j);
                    res.push_back(j+1);
                    break;
                }
            }
            flip(arr,i);
            res.push_back(i+1);
        }
        return res;
    }
};
