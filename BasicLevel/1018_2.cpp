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
        if (a == 'J' && b == 'B')
        {
            x++;
            m[2]++;
        }
        else if (a == 'B' && b == 'C')
        {
            x++;
            m[0]++;
        }
        else if (a == 'C' && b == 'J')
        {
            x++;
            m[1]++;
        }
        else if (a == 'B' && b == 'J')
        {
            y++;
            n[2]++;
        }
        else if (a == 'C' && b == 'B')
        {
            y++;
            n[0]++;
        }
        else if (a == 'J' && b == 'C')
        {
            y++;
            n[1]++;
        }
    }
    cout << x << " " << num - x - y << " " << y << endl;
    cout << y << " " << num - x - y << " " << x << endl;
    int max1 = m[0] >= m[1] ? 0 : 1;
    max1 = m[max1] >= m[2] ? max1 : 2;
    int max2 = n[0] >= n[1] ? 0 : 1;
    max2 = n[max2] >= n[2] ? max2 : 2;
    char str[4] = {"BCJ"};
    cout << str[max1] << " " << str[max2];
}