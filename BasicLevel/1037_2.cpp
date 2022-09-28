#include<iostream>
using namespace std;
const int Gallen=17*29;
const int Sickle=29;
int main()
{
    int g,s,k,a,b,c;
    scanf("%d.%d.%d%d.%d.%d",&g,&s,&k,&a,&b,&c);
    int price=g*Gallen+s*Sickle+k;
    int money=a*Gallen+b*Sickle+c;
    int diff=money-price;
    if(diff<0){
        printf("-");
        diff=(-diff);
    }
    printf("%d.%d.%d",diff/Gallen,diff%Gallen/Sickle,diff%Sickle);
    return 0;
}