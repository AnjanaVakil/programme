#include<iostream>
#include<algorithm>
using namespace std;
//不会写
void InsertSort(int n[],int size)
{
    for(int i=0;i<size;i++){
        for(int j=i;j>=0 && n[j]<n[j-1];j--){
            swap(n[j],n[j-1]);
        }
    }
}
void MergeSort(int n[],int l,int r,int temp[])
{
    if(l+1>=r) return;
    int m=l+(r-l)/2;
    MergeSort(n,l,m,temp);
    MergeSort(n,m,r,temp);
    int p=l,q=r,i=l;
    while(p<m && q<r){
        if(q>=m || (q<m && n[p]<n[q])){
            temp[i++]=n[p++];
        }else temp[i++]=n[q++];
    }
    for(i=l;i<r;i++){
        n[i]=temp[i];
    }
}
int main()
{
    int n;
    cin >> n;
    int a[101],b[101];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    
}