#include<stdio.h>
#define maxn 1005
int a[maxn];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(j%i==0){
                a[j]=-a[j];
            }
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]==1){
            printf("%d ",i);
        }
    }
    if(a[n-1]==1) printf("%d\n",n);
    return 0;
}