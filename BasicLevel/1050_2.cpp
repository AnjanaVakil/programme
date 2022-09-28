#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int N,m,n,t=0;
    cin >> N;
    for(n=sqrt((double)N);n>=1;n--){
        if(N%n==0){
            m=N/n;
            break;
        }
    }
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),cmp);
    vector< vector<int> > b(m,vector<int>(n));
    //计算螺旋矩阵的层数level，如果m的值为偶数，层数为m/2，如果m为奇数，层数为m/2+1
    //所以level = m / 2 + m % 2；
    int level=m/2+m%2;
    for(int i=0;i<level;i++){
        for(int j=i;j<=n-1-i && t<=N-1;j++){
            b[i][j]=a[t++];
        }
        for(int j=i+1;j<=m-2-i && t<=N-1;j++){
            b[j][n-1-i]=a[t++];
        }
        for(int j=n-1-i;j>=i && t<=N-1;j--){
            b[m-1-i][j]=a[t++];
        }
        for(int j=m-2-i;j>=i+1 && t<=N-1;j--){
            b[j][i]=a[t++];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << b[i][j];
            if(j!=n-1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}