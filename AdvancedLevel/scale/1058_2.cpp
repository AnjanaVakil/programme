#include<iostream>
using namespace std;
//21:30-21:44 20score
int main()
{
    //3.2.1 10.16.27
    //17 29 
    //14.1.28
    int ga,gb,sa,sb,ka,kb;
    scanf("%d.%d.%d %d.%d.%d",&ga,&sa,&ka,&gb,&sb,&kb);
    int k=ka+kb;
    int s=sa+sb+k/29;
    k=k%29;
    int g=ga+gb+s/17;
    s=s%17;
    printf("%d.%d.%d",g,s,k);
    return 0;
}