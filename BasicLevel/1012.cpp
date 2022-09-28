#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[1001];
    int a1 = 0, a2 = 0, a3 = 0;
    float avg = 0;
    int tmp = 0, cnt = 0, max = 0;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 5 == 0 && a[i] % 2 == 0)
        {
            f1 = 1;
            a1 += a[i];
        }
        else if (a[i] % 5 == 1)
        {
            f2 = 1;
            if (tmp == 0)
            {
                a2 += a[i];
                tmp = 1;
            }
            else
            {
                a2 -= a[i];
                tmp = 0;
            }
        }
        else if (a[i] % 5 == 2)
        {
            f3 = 1;
            a3 += 1;
        }
        else if (a[i] % 5 == 3)
        {
            f4 = 1;
            avg += a[i];
            cnt += 1;
        }
        else if (a[i] % 5 == 4)
        {
            f5 = 1;
            if (a[i] > max)
            {
                max = a[i];
            }
        }
    }
    avg /= cnt;
    if (f1 == 0)
    {
        cout << 'N' << " ";
    }
    else
    {
        cout << a1 << " ";
    }
    if (f2 == 0)
    {
        cout << 'N' << " ";
    }
    else
    {
        cout << a2 << " ";
    }
    if (f3 == 0)
    {
        cout << 'N' << " ";
    }
    else
    {
        cout << a3 << " ";
    }
    if (f4 == 0)
    {
        cout << 'N' << " ";
    }
    else
    {
        cout << fixed << setprecision(1) << avg << " ";
    }
    if (f5 == 0)
    {
        cout << 'N';
    }
    else
    {
        cout << max;
    }
    return 0;
}