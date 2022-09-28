#include<iostream>
using namespace std;
int main()
{
    int m,n,a,b,t,num;
    scanf("%d%d%d%d%d",&m,&n,&a,&b,&t);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j!=0) printf(" ");
            scanf("%d",&num);
            if(num>=a && num<=b){
                num=t;
            }
            printf("%03d",num);
        }
        printf("\n");
    }
    return 0;
}