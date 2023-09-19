class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int l=0,h=n-1;
        int ans=letters[0];
        while(l<=h){
            int mid=(l+h)/2;
            //greater than target
            if(letters[mid]>target){
                //this could be ans
                ans=letters[mid];
                //to find smallest letter we move to left subarray
                h=mid-1;
            }
            else    l=mid+1;
        }
        return ans;
    }
};
