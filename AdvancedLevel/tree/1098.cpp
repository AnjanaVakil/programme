#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;
int n;
int origin[maxn],tempOri[maxn],changed[maxn];
bool isSame(int A[],int B[])
{
    for(int i=1;i<=n;i++){
        if(A[i]!=B[i]) return false;
    }
    return true;
}
bool insertSort()
{
    bool flag=false;
    for(int i=2;i<=n;i++){
        if(i!=2 && isSame(tempOri,changed)){
            flag=true;
        }
        sort(tempOri,tempOri+i+1);
        if(flag==true){
            return true;
        }
    }
    return false;
}
void downAdjust(int low,int high)
{
    int i=low,j=i*2;
    while(j<=high){
        if(j+1<=high && tempOri[j+1]>tempOri[j]){
            j=j+1;
        }
        if(tempOri[j]>tempOri[i]){
            swap(tempOri[j],tempOri[i]);
            i=j;
            j=i*2;
        }else{
            break;
        }
    }
}
void showArray()
{
    for(int i=1;i<=n;i++){
        cout << tempOri[i];
        if(i<n) cout << " ";
    }
}
void heapSort()
{
    bool flag=false;
    for(int i=n/2;i>=1;i--){
        downAdjust(i,n);
    }
    for(int i=n;i>1;i--){
        if(i!=n && isSame(tempOri,changed)){
            flag=true;
        }
        swap(tempOri[i],tempOri[1]);
        downAdjust(1,i-1);
        if(flag==true){
            showArray();
            return;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> origin[i];
        tempOri[i]=origin[i];
    }
    for(int i=1;i<=n;i++){
        cin >> changed[i];
    }
    if(insertSort()){
        cout << "Insertion Sort\n";
        showArray();
        return 0;
    }else{
        cout << "Heap Sort\n";
        for(int i=1;i<=n;i++){
            tempOri[i]=origin[i];
        }
        heapSort();
    }
    return 0;
}