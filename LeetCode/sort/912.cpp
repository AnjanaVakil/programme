//选择、插入、冒泡 时间复杂度 O(N) 空间复杂度O(1) 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //选择排序:超出时间限制
        // for(int i=0;i<nums.size()-1;i++){
        //     int minPos=i;
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[j]<nums[minPos]) minPos=j;
        //     }
        //     if(minPos!=i){
        //         swap(nums[i],nums[minPos]);
        //     }
        // }
        //插入排序:超出时间限制
        // for(int i=0;i<nums.size();i++){
        //     int temp=nums[i];
        //     int j;
        //     for(j=i;j>=1 && temp<nums[j-1];j--){
        //         nums[j]=nums[j-1];
        //     }
        //     nums[j]=temp;
        // }
        //插入排序:超出时间限制
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j>0 && nums[j]<nums[j-1];j--){
        //         swap(nums[j],nums[j-1]);
        //     }
        // }
        //冒泡排序:超出时间限制
        //小元素上浮
        // for(int i=0;i<nums.size();i++){
        //     bool swapped=false;
        //     for(int j=nums.size()-1;j>i;j--){
        //         if(nums[j]<nums[j-1]){
        //             swap(nums[j],nums[j-1]);
        //             swapped=true;
        //         }
        //     }
        //     if(!swapped) break;
        // }
        return nums;
    }
};
//归并排序
class Solution {
public:
    vector<int> tmp;
    vector<int> sortArray(vector<int>& nums) {
        //归并排序:时间复杂度O(NlogN)
        tmp.resize(nums.size(),0);
        mergeSort(nums,0,nums.size()-1);
        return nums;
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
            if(nums[i]<nums[j]){
                tmp[cnt++]=nums[i++];
            }else{
                tmp[cnt++]=nums[j++];
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
//快速排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums,0,nums.size()-1);
        return nums;
    }
    int partition(vector<int>& nums,int left,int right){
        int pivot=nums[right];
        int i=left-1;
        for(int j=left;j<right;j++){
            if(nums[j]<=pivot){
                swap(nums[j],nums[i+1]);
                i+=1;
            }
        }
        swap(nums[i+1],nums[right]);
        int pos=i+1;
        return pos;
    }
    int radomized_partition(vector<int>& nums,int left,int right){
        int i=rand()%(right-left+1)+left; //随机选取一个作为主元
        swap(nums[i],nums[right]);
        return partition(nums,left,right);
    }
    void randomized_quicksort(vector<int>& nums,int left,int right){
        if(left<right){
            int pos=radomized_partition(nums,left,right);
            randomized_quicksort(nums,left,pos-1);
            randomized_quicksort(nums,pos+1,right);
        }
    }
};



