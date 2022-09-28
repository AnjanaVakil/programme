#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("Case #%d: ",i+1);
        long long sum=a+b;
        if(a>0 && b>0 && sum<0){
            //正数相加 等于 负数，溢出
            printf("true\n");
        }else if(a<0 && b<0 && sum>=0){
            //负数相加 等于 正数，溢出
            printf("false\n");
        }else if(sum>c){
            printf("true\n");
        }else{
            printf("false\n");
        }
    }
    return 0;
}