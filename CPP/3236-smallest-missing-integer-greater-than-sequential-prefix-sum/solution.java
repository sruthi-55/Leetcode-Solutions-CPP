class Solution {
    public int missingInteger(int[] nums) {
        // nums = [1,2,3,2,5]
        if(nums.length==1) return nums[0]+1;
        int sum =nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i]==nums[i-1]+1) sum+=nums[i];
            else break;
        }
        Arrays.sort(nums);
        List<Integer>arr = new ArrayList<>();
        for(int i=0;i<nums.length;i++) arr.add(nums[i]);
        for(int i=0;i<arr.size();i++){
            if(!arr.contains(sum)) return sum;
            else sum++;
        }
        return arr.get(arr.size()-1)+1;
    }
}
