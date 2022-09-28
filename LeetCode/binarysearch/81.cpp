//数组中的值不必互不相同。
//数组中有重复元素
//因为数组存在重复数字，如果中点和左端的数字相同，我们并不能确定是左区间全部相同，还是右区间完全相同。
//在这种情况下，我们可以简单地将左端点右移一位，然后继续进行二分查找。
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+((right-left)>>1);
            if(target==nums[mid]){
                return true;
            }
            if(nums[mid]==nums[left]){
                left++;
            }else if(nums[mid]>nums[left]){
                //左区间有序
                if(target>=nums[left] && target<=nums[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(target>=nums[mid] && target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return false;
    }
};
//
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+((right-left)>>1);
            if(target==nums[mid]){
                return true;
            }
            if(nums[mid]==nums[left] && nums[mid]==nums[right]){
                left++;
                right--;
            }else if(nums[mid]>=nums[left]){
                //左区间有序
                if(target>=nums[left] && target<=nums[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(target>=nums[mid] && target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return false;
    }
};
