//小元素上浮
void BubbleSort(vector<T> &x)
{
    int n=s.size();
    T temp;
    for(int i=1;i<n;i++){
        int flag=0;
        for(int j=n-1;j>i;j--){
            if(x[j]<x[j-1]){
                swap(x[j],x[j-1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}
//大元素下沉
void BubbleSort(vector<T> &x)
{
    int n=x.size();
    T temp;
    for(int i=n-1;i>=0;i--){
        int flag=0;
        for(int j=0;j<i;j++){
            if(x[j]>x[j+1]){
                swap(x[j],x[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}