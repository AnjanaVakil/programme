#include<stdio.h>
#define maxn 1000+10
int main()
{
    int n,a[maxn],b[maxn],kase=0;
    while(scanf("%d",&n)==1 && n){
        printf("Game %d",++kase);
        for(int i=0;i<n;i++){
            scanf("%d:",&a[i]);
        }
        for(;;){
            int A=0,B=0;
            for(int i=0;i<n;i++){
                scanf("%d",&b[i]);
                if(a[i]==b[i]) A++;
            }
            if(b[0]==0) break;
            for(int d=1;d<=9;d++){
                int c1=0,c2=0;
                for(int i=0;i<n;i++){
                    if(a[i]==d) c1++;
                    if(b[i]==d) c2++;
                }
                if(c1<c2) B+=c1;
                else B+=c2;
            }
            //B-A;统计a[i]和b[i]所有具有相同元素的个数-元素相同位置也相同的元素个数=两个数组中元素相同位置不相同的个数
            printf("    (%d,%d)\n",A,B-A);
        }
    }
    return 0;
}
/*
4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0
*/