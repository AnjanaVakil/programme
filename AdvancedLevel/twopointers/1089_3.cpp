#include<iostream>
#include<algorithm>
using namespace std;
//25'
const int maxn=110;
int origin[maxn],part[maxn];
int n;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> origin[i];
    }
    for(int i=0;i<n;i++){
        cin >> part[i];
    }
    int i,j;
    for(i=0;i<n-1 && part[i]<=part[i+1];i++);
    for(j=i+1;j<n && origin[j]==part[j];j++);
    if(j==n){
        cout << "Insertion Sort\n";
        sort(origin,origin+i+2);
    }else{
        cout << "Merge Sort\n";
        bool flag=true;
        int k=1;
        while(flag){
            //这句很重要
            flag=false;
            for(int i=0;i<n;i++){
                if(origin[i]!=part[i]){
                    flag=true;
                }
            }
            k=k*2;
            for(int i=0;i<n/k;i++){
                sort(origin+i*k,origin+(i+1)*k);
            }
            sort(origin+n/k*k,origin+n);
        }
    }
    for(j=0;j<n;j++){
        if(j!=0) cout << " ";
        cout << origin[j];
    }
    return 0;
}