//不要用else，将所有的else if都写出来，方便理解
int binary_search(vector<int>& nums,int target){
    int left=0,right=nums.size()-1;
    //注意：是left <= right
    while(left<=right){
        int mid=left+(right-left)/2;
        if(target==nums[mid]){
            return mid;
        }else if(target<nums[mid]){
            right=mid-1;
        }else if(target>nums[mid]){
            left=mid+1;
        }
    }
    return -1;
}
//
int left_bound(vector<int>& nums,int target){
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(target==nums[mid]){
            right=mid-1;
        }else if(target<nums[mid]){
            right=mid-1;
        }else if(target>nums[mid]){
            left=mid+1;
        }
    }
    if(left>=nums.size() || nums[left]!=target) return -1;
    return left;
}
//
int right_bound(vector<int>& nums,int target){
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(target==nums[mid]){
            left=mid+1;
        }else if(target<nums[mid]){
            right=mid-1;
        }else if(target>nums[mid]){
            left=mid+1;
        }
    }
    if(right<0 || nums[right]!=target) return -1;
    return right;
}