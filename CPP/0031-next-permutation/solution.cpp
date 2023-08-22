class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size();
        //from the right find the first pair where a[i]<a[i+1]
        int i;
        for(i=n-2;i>=0;i--){
            if(a[i]<a[i+1]) break;
        }
        if(i<0){
            reverse(a,0,n-1);
            return;
        } 
        //swap a[i] with number just larger than it from right part
        int j;
        for(j=n-1;j>=i;j--){
            if(a[j]>a[i]){
                swap(a,i,j);
                break;
            }   
        }
        //reverse the right part 
        reverse(a,i+1,n-1);
    }
    void swap(vector<int> &a,int i,int j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    void reverse(vector<int> &a,int s,int e){
        while(s<=e){
            swap(a,s,e);
            s++;e--;
        }
    }
};
