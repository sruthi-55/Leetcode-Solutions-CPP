class Solution {
public:
    void swap(string &a,int i,int j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    void reverse(string &a,int s,int e){
        while(s<=e){
            swap(a,s,e);
            s++;e--;
        }
    }
    void nextPermutation(string &a) {
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
    int getMinSwaps(string num, int k) {
        int count=0;
        string next=num;
        //next permutation of given number
        while(k--){
            nextPermutation(next);
        }
        //i points to num and next
        //k is used to find the mismatched character in next
        //num:  0 5 9
        //next: 9 5 0(k)
        for(int i=0;i<num.size();i++){
            if(num[i]!=next[i]){
                int k=i+1;
                while(next[k]!=num[i])  k++;
                while(k>i){
                    swap(next,k,k-1);
                    count++;
                    k--;
                }
            }
        }
        return count;
    }
};

//0 5 9
//0 9 5
//5 0 9
//5 9 0
//9 0 5
//9 5 0  --ans: 3

//0 0 1 2 3
//0 0 1 3 2  --ans: 1
