class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int majEle=arr[0];
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==majEle)  count++;
            else    count--;
            if(count==0)    majEle=arr[i+1];
        }
        return majEle;
    }
};
