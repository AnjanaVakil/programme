#include <iostream>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    int hash[256] = {0};
    while (i < a.length())
    {
        if (a[i] != b[j])
        {
            if (a[i] >= 'a' && a[i] <= 'z')
            {
                a[i] -= 32;
            }
            hash[a[i]] = 1;
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] -= 32;
        }
        if (hash[a[i]] == 1)
        {
            cout << a[i];
            hash[a[i]]=0;
        }
    }
    return 0;
}