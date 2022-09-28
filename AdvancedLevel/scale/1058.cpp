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
    int g=ga+gb,s=sa+sb,k=ka+kb;
    int temp;
    if(k>=29){
        temp=k/29;
        k-=(temp*29);
        s+=temp;
    }
    if(s>=17){
        temp=s/17;
        s-=(temp*17);
        g+=temp;
    }
    printf("%d.%d.%d",g,s,k);
    return 0;
}