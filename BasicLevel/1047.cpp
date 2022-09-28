#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c;
    cin >> n;
    int team[1001] = {0};
    while (n--)
    {
        scanf("%d-%d %d", &a, &b, &c);
        team[a] += c;
    }
    int max = team[0];
    for (int i = 0; i < 1000; i++)
    {
        if (team[i + 1] > team[max])
        {
            max = i + 1;
        }
    }
    cout << max << " " << team[max];
}