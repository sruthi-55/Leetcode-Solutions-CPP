class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele1=-1,ele2=-1;
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(count1==0 && ele2!=nums[i]){
                ele1 = nums[i];
                count1=1;
            }
            else if(count2==0 && ele1!=nums[i]){
                ele2 = nums[i];
                count2=1;
            }
            else if(ele1 == nums[i])  count1++;
            else if(ele2 == nums[i])    count2++;
            else{
                count1--;   count2--;
            }
        }

        count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1)   count1++;
            else if(nums[i]==ele2)   count2++;
        }
        int limit = floor(n/3.0);
        vector<int> res;
        if(count1>limit)   res.push_back(ele1);
        if(count2>limit)   res.push_back(ele2);
        return res;
    }
};
