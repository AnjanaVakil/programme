#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    //在不允许使用另外数组的前提下
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    m = m % n;
    if (m != 0)
    {
        //2种都可
        // reverse(a.begin(), a.end());
        // reverse(a.begin(), a.begin() + m);
        // reverse(a.begin() + m, a.end());
        reverse(begin(a), begin(a) + n);
        reverse(begin(a), begin(a) + m);
        reverse(begin(a) + m, begin(a) + n);
    }
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1];
    return 0;
}