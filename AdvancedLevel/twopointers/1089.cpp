#include<iostream>
#include<algorithm>
using namespace std;
//25'
int initial[101],temp[101],res[101];
int n;
bool isSame(int A[],int B[])
{
    for(int i=0;i<n;i++){
        if(A[i]!=B[i]) return false;
    }
    return true;
}
void showArray(int A[])
{
    for(int i=0;i<n;i++){
        if(i!=0) cout << " ";
        cout << A[i];
    }
}
bool insertSort()
{
    bool flag=false;
    for(int i=1;i<n;i++){
        if(i!=1 && isSame(temp,res)){
            flag=true;
        }
        int tempnum=temp[i];
        int j;
        for(j=i;j>0 && tempnum<temp[j-1];j--){
            temp[j]=temp[j-1];
        }
        temp[j]=tempnum;
        if(flag==true){
            return true;
        }
    }
    return false;
}
void mergeSort()
{
    bool flag=false;
    for(int step=2;step/2<=n;step*=2){
        if(step!=2 && isSame(temp,res)){
            flag=true;
        }
        for(int i=0;i<n;i+=step){
            sort(temp+i,temp+min(i+step,n));
        }
        //可以输出归并排序某一趟结束的序列
        if(flag==true){
            showArray(temp);
            return;
        }
    }
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> initial[i];
        temp[i]=initial[i];
    }
    for(int i=0;i<n;i++){
        cin >> res[i];
    }
    if(insertSort()){
        cout << "Insertion Sort\n";
        showArray(temp);
    }else{
        cout << "Merge Sort\n";
        for(int i=0;i<n;i++){
            temp[i]=initial[i];
        }
        mergeSort();
    }
    return 0;
}