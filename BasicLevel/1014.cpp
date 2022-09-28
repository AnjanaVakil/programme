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
    switch ((t[0] - 'A' + 1))
    {
    case 1:
        cout << "MON"
             << " ";
        break;
    case 2:
        cout << "TUE"
             << " ";
        break;
    case 3:
        cout << "WED"
             << " ";
        break;
    case 4:
        cout << "THU"
             << " ";
        break;
    case 5:
        cout << "FRI"
             << " ";
        break;
    case 6:
        cout << "SAT"
             << " ";
        break;
    case 7:
        cout << "SUN"
             << " ";
        break;
    }
    if (t[1] >= '0' && t[1] <= '9')
    {
        printf("%02d:",t[1]-'0');
    }
    if (t[1] >= 'A' && t[1] <= 'N')
    {
        printf("%02d:",t[1]-'A'+10);
    }
    printf("%02d",pos);
    return 0;
}