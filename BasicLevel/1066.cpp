#include<iostream>
using namespace std;
int main()
{
    //有一个得分点运行超时
    //发现用cin输入会超时，用scanf不会有超时问题
    // int m,n,a,b,t,num;
    // cin >> m >> n >> a >> b >> t;
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         if(j!=0) printf(" ");
    //         cin >> num;
    //         if(num>=a && num<=b){
    //             printf("%03d",t);
    //         }else{
    //             printf("%03d",num);
    //         }
    //     }
    //     printf("\n");
    // }
    int m,n,a,b,t,num;
    scanf("%d%d%d%d%d",&m,&n,&a,&b,&t);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j!=0) printf(" ");
            scanf("%d",&num);
            if(num>=a && num<=b){
                printf("%03d",t);
            }else{
                printf("%03d",num);
            }
        }
        printf("\n");
    }
    return 0;
}