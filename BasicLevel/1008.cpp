#include <iostream>
using namespace std;
int main()
{
    //在不允许使用另外数组的前提下
    int n, m;
    cin >> n >> m;
    int a[101];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    m = m % n; //没有这个m=m%n的话就是部分正确
    for (int i = n - m; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < n - m - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n - m - 1];
}