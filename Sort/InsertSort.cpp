void InsertSort(vector<T> &x)
{
    int n=x.size();
    int next,j;
    T temp;
    for(next=2;next<n;next++){
        temp=x[next];
        for(j=next-1;j>=1 && temp<x[j];j--){
            x[j+1]=x[j];
        }
        x[j+1]=temp;
    }
}
void InsertSort(ElemType A[],int n)
{
    for(int i=0;i<n;i++){
        temp=A[i];
        for(int j=i;j>=0 && A[j-1]>temp;j--){
            A[j]=A[j-1];
        }
        A[j]=temp;
    }
}