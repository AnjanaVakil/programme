#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, num, a1 = 0, a2 = 0, max = 0;
    cin >> n;
    double avg = 0.0;
    vector<int> v[5];
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[num % 5].push_back(num);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (i == 0 && v[i][j] % 2 == 0)
                a1 += v[i][j];
            if (i == 1 && j % 2 == 0)
                a2 += v[i][j];
            if (i == 1 && j % 2 == 1)
                a2 -= v[i][j];
            if (i == 3)
                avg += v[i][j];
            if (i == 4 && v[i][j] > max)
                max = v[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (i != 0)
            printf(" ");
        if (i == 0 && a1 == 0 || i != 0 && v[i].size() == 0)
        {
            printf("N");
            continue;
        }
        if (i == 0)
            printf("%d", a1);
        if (i == 1)
            printf("%d", a2);
        if (i == 2)
            printf("%d", v[2].size());
        if (i == 3)
            printf("%.1f", avg /= v[3].size());
        if (i == 4)
            printf("%d", max);
    }
    return 0;
}