#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int N,m,n;
    cin >> N;
    for(n=sqrt(double(N));n>=1;n--){
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
    int x=0,y=0,t=0;
    b[x][y]=a[0];
    while (t<N-1)
    {
        while (y + 1 < n && !b[x][y + 1])
            b[x][++y] = a[++t];
        //预判(是否出界或者是否已经是填过的格子)
        while (x + 1 < m && !b[x + 1][y]) //!a[x+1][y]即a[x+1][y]==0
            b[++x][y] = a[++t];
        while (y - 1 >= 0 && !b[x][y - 1])
            b[x][--y] = a[++t];
        while (x - 1 >= 0 && !b[x - 1][y])
            b[--x][y] = a[++t];
    }
    for (x = 0; x < m; x++)
    {
        for (y = 0; y < n; y++)
        {
            printf("%d", b[x][y]);
            if(y!=n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}