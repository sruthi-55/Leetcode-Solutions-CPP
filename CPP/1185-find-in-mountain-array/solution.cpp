/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left=-1,right=-1;
        //binary search to find peak
        int l=0,h=mountainArr.length()-1;
        int peak=0;
        int mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }
            else{
                peak=mid;
                h=mid-1;
            } 
        }

        //finding target in left mountain
        l=0;
        h=peak;
        while(l<=h){
            mid=l+(h-l)/2;
            if(mountainArr.get(mid)==target){
                left=mid;
                h=mid-1;
            }    
            if(mountainArr.get(mid)>target) h=mid-1;
            else    l=mid+1;
        }
        if(left!=-1)    return left;

        //finding target in right mountain
        l=peak;
        h=mountainArr.length()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mountainArr.get(mid)==target){
                right=mid;
                h=mid-1;
            }    
            if(mountainArr.get(mid)>target) l=mid+1;
            else    h=mid-1;
        }
        return right;
    }
};
