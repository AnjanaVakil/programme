#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    set<int> S;
    int i;
    set<int>::iterator j;
    while (cin >> i)
        S.insert(i);
    for (j = S.begin(); j != S.end(); ++j)
        cout << *j << "\n";
    return 0;
}
// int a[1000000];
// int main()
// {
//     int i, n = 0;
//     while (scanf("%d", &a[n]) != EOF)
//     {
//         n++;
//     }
//     sort(a, a + n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\n", a[i]);
//     }
//     return 0;
// }