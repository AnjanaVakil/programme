class Solution {
public:
    int reversePairs(vector<int>& nums) {
        //超过时间限制
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[i]) cnt++;
            }
        }
        return cnt;
    }
};
//超出时间限制
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int size=nums.size();

        if(size<2) return 0;

        vector<int> copy(size);
        for(int i=0;i<size;i++){
            copy[i]=nums[i];
        }

        vector<int> temp(size);
        return reversePairs(copy,0,size-1,temp);
    }
    int reversePairs(vector<int>& nums,int left,int right,vector<int>& temp){
        if(left==right) return 0;

        int mid=left+(right-left)/2;
        int leftPairs=reversePairs(nums,left,mid,temp);
        int rightPairs=reversePairs(nums,mid+1,right,temp);
        
        if(nums[mid]==nums[mid+1]){
            return leftPairs+rightPairs;
        }

        int crossPairs=mergeAndCount(nums,left,mid,right,temp);
        return leftPairs+rightPairs+crossPairs;
    }
    int mergeAndCount(vector<int>& nums,int left,int mid,int right,vector<int> temp){
        for(int i=left;i<=right;i++){
            temp[i]=nums[i];
        }

        int i=left,j=mid+1;

        int count=0;
        for(int k=left;k<=right;k++){
            if(i==mid+1){
                nums[k]=temp[j++];
            }else if(j==right+1){
                nums[k]=temp[i++];
            }else if(temp[i]<=temp[j]){
                nums[k]=temp[i++];
            }else{
                nums[k]=temp[j++];
                count+=(mid-i+1);
            }
        }
        return count;
    }
};
//runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
class Solution {
public:
    vector<int> tmp;
    int reversePairs(vector<int>& nums) {
        return countInver(nums,0,nums.size()-1);
    }
    int countInver(vector<int>& nums,int left,int right){
        if(left>=right) return 0;
        int mid=left+(right-left)/2;
        int s1=countInver(nums,left,mid);
        int s2=countInver(nums,mid+1,right);
        int s3=mergeCount(nums,left,mid,right);
        return s1+s2+s3;
    }
    int mergeCount(vector<int>& nums,int left,int mid,int right){
        int s3=0;
        int i=left,j=mid+1;
        int cnt=0;
        while(i<=mid && j<=right){
            if(nums[i]<nums[j]){
                tmp[cnt++]=nums[i++];
            }else{
                tmp[cnt++]=nums[j++];
                s3=s3+(mid-i+1);
            }
        }
        if(i<=mid){
            tmp[cnt++]=nums[i++];
        }
        if(j<=right){
            tmp[cnt++]=nums[j++];
        }
        for(int i=0;i<right-left+1;i++){
            nums[i+left]=tmp[i];
        }
        return s3;
    }
};
//通过
class Solution {
public:
    vector<int> tmp;
    int count=0;
    int reversePairs(vector<int>& nums) {
        tmp.resize(nums.size(),0);
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
    void mergeSort(vector<int>& nums,int left,int right){
        //递归终止：仅有一个元素
        if(left>=right) return;
        // int mid=(left+right)/2;
        int mid=(left+right)>>1;

        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);

        int i=left,j=mid+1,cnt=0;
        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){
                tmp[cnt++]=nums[i++];
            }else{
                tmp[cnt++]=nums[j++];
                count+=(mid-i+1);
            }
        }
        while(i<=mid){
            tmp[cnt++]=nums[i++];
        }
        while(j<=right){
            tmp[cnt++]=nums[j++];
        }

        for(int i=0;i<right-left+1;i++){
            nums[i+left]=tmp[i];
        }
    }
};
//通过
class Solution {
public:
    vector<int> temp;
    int count=0;
    int reversePairs(vector<int>& nums) {
        temp.resize(nums.size(),0);
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
    void mergeSort(vector<int>& nums,int left,int right){
        //递归终止：仅有一个元素
        if(left>=right) return;
        // int mid=(left+right)/2;
        int mid=(left+right)>>1;

        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);

        int i=left,j=mid+1;
        for(int k=left;k<=right;k++){
            temp[k]=nums[k];
        }
        
        int index=left;
        while(i<=mid || j<=right){
            if(i>mid){
                nums[index++]=temp[j++];
            }else if(j>right){
                nums[index++]=temp[i++];
            }else if(temp[i]<=temp[j]){
                nums[index++]=temp[i++];
            }else{
                nums[index++]=temp[j++];
                count+=(mid-i+1);
            }
        }
    }
};
//通过
class Solution {
public:
    vector<int> temp;
    int count=0;
    int reversePairs(vector<int>& nums) {
        temp.resize(nums.size());
        sort(nums,0,nums.size()-1);
        return count;
    }
    void sort(vector<int>& nums,int left,int right){
        //递归终止：仅有一个元素
        if(left>=right) return;
        int mid=(left+right)/2;
        // int mid=(left+right)>>1;

        sort(nums,left,mid);
        sort(nums,mid+1,right);

        merge(nums,left,mid,right);
    }
    void merge(vector<int>& nums,int left,int mid,int right){
        int i=left,j=mid+1;
        for(int k=left;k<=right;k++){
            temp[k]=nums[k];
        }
        
        int cnt=left;
        while(i<=mid || j<=right){
            if(i>mid){
                nums[cnt++]=temp[j++];
            }else if(j>right){
                nums[cnt++]=temp[i++];
            }else if(temp[i]<=temp[j]){ //细心啊，这边写成i++和j++导致找了很久的错误
                nums[cnt++]=temp[i++];
            }else{
                nums[cnt++]=temp[j++];
                count+=(mid-i+1);
            }
        }
    }
};