#include <iostream>
using namespace std;
int main()
{
    int a, b, da, db;
    cin >> a >> da >> b >> db;
    int num;
    int res1 = 0;
    while (a != 0)
    {
        num = a % 10;
        if (num == da)
        {
            res1 = res1 * 10 + da;
        }
        a /= 10;
    }
    int res2 = 0;
    while (b != 0)
    {
        num = b % 10;
        if (num == db)
        {
            res2 = res2 * 10 + db;
        }
        b /= 10;
    }
    cout << res1 + res2;
}