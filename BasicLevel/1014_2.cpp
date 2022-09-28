#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int i = 0, j = 0, pos;
    char t[2];
    while (i < a.length() && i < b.length())
    {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G'))
        {
            t[0] = a[i];
            break;
        }
        i++;
    }
    i += 1;
    while (i < a.length() && i < b.length())
    {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || (a[i] >= '0' && a[i] <= '9')))
        {
            t[1] = a[i];
            break;
        }
        i++;
    }
    while (j < c.length() && j < d.length())
    {
        if (c[j] == d[j] && isalpha(c[j]))
        {
            pos = j;
            break;
        }
        j++;
    }
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int m = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;
    cout << week[t[0] - 'A'];
    printf(" %02d:%02d", m, pos);
    return 0;
}