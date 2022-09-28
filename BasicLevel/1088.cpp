#include <iostream>
using namespace std;
//丙可能是小数，所以还有int和double的比较
// string cmp(int a, int b)
// {
//     if (a < b)
//         return " Cong";
//     else if (a == b)
//         return " Ping";
//     else
//         return " Gai";
// }
//将m设为全局变量，这样就可以直接比较了
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
    cin >> m >> x >> y;
    for (int a = 99; a >= 10; a--)
    {
        int b = a % 10 * 10 + a / 10;
        double c = abs(b - a) * 1.0 / x;
        if (b == c * y)
        {
            cout << a;
            print(a);
            print(b);
            print(c);
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}
