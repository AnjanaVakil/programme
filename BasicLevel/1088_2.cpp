#include <iostream>
using namespace std;
int m,x,y;
void print(double t)
{
    if(m==t) printf(" Ping");
    else if(m<t) printf(" Cong");
    else printf(" Gai");
}
int main()
{
    //丙不一定是int值，可能是4.5这样的数字～所以要用double存储丙
    scanf("%d %d %d",&m,&x,&y);
    for(int i=99;i>=10;i--){
        int j=i%10*10+i/10;
        double k=abs(j-i)*1.0/x;
        if(j==k*y){
            cout << i;
            print(i);
            print(j);
            print(k);
            //要学会擅用return 0
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}
