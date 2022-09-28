//非递归
void mergeSort(int A[],int n)
{
    for(int step=2;step/2<=n;step*=2){
        for(int i=1;i<=n;i+=step){
            int mid=i+step/2-1;
            if(mid+1<n){
                merge(A,i,mid,mid+1,min(i+step-1,n));
                // merge(A,L1,R1,L2,R2);
            }
        }
    }
}
//非递归
void mergeSort(int A[],int n)
{
    for(int step=2;step/2<=n;step*=2){
        for(int i=1;i<=n;i+=step){
            sort(A+i,A+min(i+step,n+1));
        }
        //可以输出归并排序某一趟结束的序列
    }
}