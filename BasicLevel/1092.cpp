#include<iostream>
#include<string.h>
using namespace std;
#define maxn 1000000
int a[105][1005];
int b[maxn];
int main()
{
    int n,m,max=-1,first=1;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    memset(b,0,sizeof(b));
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            b[j]+=a[i][j];
        }
        if(b[j]>max){
            max=b[j];
        }
    }
    cout << max << endl;
    for(int j=0;j<n;j++){
        if(b[j]==max){
            if(!first) cout << " ";
            cout << j+1;
            first=0;
        }
    }
    return 0;
}