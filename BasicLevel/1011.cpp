#include <iostream>
using namespace std;
int main()
{
    long t, a, b, c;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;
        cout << "Case #" << i + 1 << ": ";
        if (a + b > c)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}