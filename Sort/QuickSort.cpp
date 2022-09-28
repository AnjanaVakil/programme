template<class T>
void QuickSort(vector<T> &x)
{
    QuickSort_sub(x,0,size-1);
}
void QuickSort_sub(vector<T> &x,int first,int last)
{
    if(first<last){
        int pos=split(x,fist,last);
        QuickSort_sub(x,fist,pos-1);
        QuickSort_sub(x,pos+1,last);
    }
}
int split(vector<T> &x,int first,int last)
{
    ElemType pivot=x[first];
    int Left=first,Right=last;
    while(Left<Right){
        while(pivot<x[Right]) Right--;
        while(pivot>x[Left]) Left++;
        if(Left<Right) swap(x[Left],x[Right]);
    }
    int pos=right;
    x[fist]=x[pos];
    x[pos]=pivot;
    return pos;
}