#include <iostream>
using namespace std;
int main()
{
    int num, x = 0, y = 0, z = 0;
    cin >> num;
    char a, b;
    int m[3] = {0}, n[3] = {0};
    for (int i = 0; i < num; i++)
    {
        cin >> a >> b;
        if ((a == 'J' && b == 'B') || (a == 'B' && b == 'C') || (a == 'C' && b == 'J'))
        {
            x++;
            if (a == 'J')
            {
                m[2]++;
            }
            else if (a == 'B')
            {
                m[0]++;
            }
            else
            {
                m[1]++;
            }
        }
        else if (a == b)
        {
            y++;
        }
        else
        {
            z++;
            if (b == 'J')
            {
                n[2]++;
            }
            else if (b == 'B')
            {
                n[0]++;
            }
            else
            {
                n[1]++;
            }
        }
    }
    cout << x << " " << y << " " << z << endl;
    cout << z << " " << y << " " << x << endl;
    int max1 = m[0] >= m[1] ? 0 : 1;
    max1 = m[max1] >= m[2] ? max1 : 2;
    int max2 = n[0] >= n[1] ? 0 : 1;
    max2 = n[max2] >= n[2] ? max2 : 2;
    char str[4] = {"BCJ"};
    cout << str[max1] << " " << str[max2];
}