#include<iostream>
#include<algorithm>
using namespace std;
//25'
const int maxn=110;
int n;
int ini[maxn],part[maxn],temp[maxn];
bool isSame(int a[],int b[])
{
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}
bool isInsert()
{
    bool flag=false;
    for(int i=1;i<n;i++){
        if(i!=1 && isSame(temp,part)){
            flag=true;
        }
        int tempnum=temp[i];
        int j=i;
        while(j>0 && tempnum<temp[j-1]){
            temp[j]=temp[j-1];
            j--;
        }
        temp[j]=tempnum;
        if(flag==true) return true;
    }
    return false;
}
void showArray(int temp[])
{
    for(int i=0;i<n;i++){
        if(i!=0) cout << " ";
        cout << temp[i];
    }
}
void mergeSort()
{
    bool flag=false;
    for(int step=2;step/2<=n;step*=2){
        if(step!=2 && isSame(temp,part)){
            flag=true;
        }
        for(int i=0;i<n;i+=step){
            sort(temp+i,temp+min(i+step,n));
        }
        if(flag){
            showArray(temp);
            return;
        }
    }
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ini[i];
        temp[i]=ini[i];
    }
    for(int i=0;i<n;i++){
        cin >> part[i];
    }
    if(isInsert()){
        cout << "Insertion Sort\n";
        showArray(temp);
    }else{
        cout << "Merge Sort\n";
        for(int i=0;i<n;i++){
            temp[i]=ini[i];
        }
        mergeSort();
    }
    return 0;
}