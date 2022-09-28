#include<stdio.h>
#define INF 1000000000
int main()
{
    int x,n,kase=0;
    while(scanf("%d",&n)==1 && n){
        int min=INF,max=-INF,s=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            s+=x;
            if(x<min) min=x;
            if(x>max) max=x;
        }
        if(kase) printf("\n");
        printf("Case %d:%d %d %.3f\n",++kase,min,max,(double)s/n);
    }
    return 0;
}