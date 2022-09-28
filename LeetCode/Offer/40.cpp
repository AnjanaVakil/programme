//排序 时间复杂度O(NlogN) 空间复杂度O(logN)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> res(k);
        for(int i=0;i<k;i++){
            res[i]=arr[i];
        }
        return res;
    }
};
//基于快排思想 
//时间复杂度:期望O(N) 最坏O(N^2) 
//空间复杂度:期望O(logN) 最坏O(N)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        random_select(arr,0,arr.size()-1,k);
        vector<int> res(k);
        for(int i=0;i<k;i++){
            res[i]=arr[i];
        }
        return res;
    }
    void random_select(vector<int>& arr,int left,int right,int k){
        if(left>=right) return;
        int pos=random_partition(arr,left,right);
        //pivot 是数组中第 pos - l + 1 小的数
        int num=pos-left+1;
        if(k==num){
            //pivot 就是第 k 小的数，直接返回即可；
            return;
        }else if(k>num){
            //表示第 k 小的数在 pivot 的右侧，因此递归调用 randomiz_select(arr, pos + 1, r, k - (pos - l + 1))；
            return random_select(arr,pos+1,right,k-num);
        }else{
            //表示第 k 小的数在 pivot 的左侧，递归调用 randomized_selected(arr, l, pos - 1, k)。
            return random_select(arr,left,pos-1,k);
        }
    }
    int random_partition(vector<int>& arr,int left,int right){
        int i=rand()%(right-left+1)+left;
        swap(arr[i],arr[right]);
        return partition(arr,left,right);
    }
    int partition(vector<int>& arr,int left,int right){
        int pivot=arr[right];
        int i=left-1;
        for(int j=left;j<right;j++){
            if(arr[j]<=pivot){
                swap(arr[j],arr[i+1]);
                i+=1;
            }
        }
        swap(arr[i+1],arr[right]);
        int pos=i+1;
        return pos;
    }
};
//最大堆
//C++ 语言中的堆（即优先队列）为大根堆
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k,0);
        if(k==0) return vec;
        priority_queue<int> Q;
        for(int i=0;i<k;i++){
            Q.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(Q.top()>arr[i]){
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for(int i=0;i<k;i++){
            vec[i]=Q.top();
            Q.pop();
        }
        return vec;
    }
};







