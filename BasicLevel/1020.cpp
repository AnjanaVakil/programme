#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct mooncake
{
    float stock, price, unit;
};
bool cmp(mooncake a, mooncake b)
{
    return a.unit > b.unit;
}
int main()
{
    int N, D;
    cin >> N >> D;
    vector<mooncake> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i].stock;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> a[i].price;
    }
    for (int i = 0; i < N; i++)
    {
        a[i].unit = a[i].price / a[i].stock;
    }
    sort(a.begin(), a.end(), cmp);
    float res = 0;
    for (int i = 0; i < N; i++)
    {
        if (D != 0)
        {
            res += a[i].unit * (a[i].stock > D ? D : a[i].stock);
            D -= (a[i].stock > D ? D : a[i].stock);
        }
        else
        {
            break;
        }
    }
    printf("%.2f", res);
    return 0;
}