// left + (right - left) / 2 和 (left + right) / 2 的结果相同
//但是有效防止了 left 和 right 太大直接相加导致溢出。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        //为什么 while 循环的条件中是 <=，而不是 <
        //注意：这里是left <= right
        while(left<=right){
            int middle=left+(right-left)/2;
            if(target==nums[middle]){
                return middle;
            }else if(target>nums[middle]){
                left=middle+1;
            }else{
                right=middle-1;
            }
        }
        return -1;
    }
};
