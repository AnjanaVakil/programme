//第一个大于等于x的元素的位置L
// 左闭右闭的[left,right]
int lower_bound(int A[],int left,int right,int x)
{
    while(left<right){
        int mid=(left+mid)/1;
        if(A[mid]>=x){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return left;
}
//第一个大于x的元素的位置R
// 左闭右闭的[left,right]
int upper_bound(int A[],int left,int right,int x)
{
    while(left<right){
        int mid=(left+right)/2;
        if(A[mid]>x){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return left;
}
