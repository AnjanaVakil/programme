#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int num[6] = {0};
    char str[] = {'P', 'A', 'T', 'e', 's', 't'};
    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case 'P':
            num[0]++;
            break;
        case 'A':
            num[1]++;
            break;
        case 'T':
            num[2]++;
            break;
        case 'e':
            num[3]++;
            break;
        case 's':
            num[4]++;
            break;
        case 't':
            num[5]++;
            break;
        }
    }
    int max = num[0];
    for (int i = 1; i < 6; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
    }
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (num[j] != 0)
            {
                cout << str[j];
                num[j]--;
            }
        }
    }
    return 0;
}