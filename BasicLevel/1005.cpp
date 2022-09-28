#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, k, flag = 0;
    cin >> n;
    vector<int> v(n);
    int arr[10000] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v[i] = k;
        while (k != 1)
        {
            if (k % 2 != 0)
                k = 3 * k + 1;
            k /= 2;
            if (arr[k] == 1)
                break;
            arr[k] = 1;
        }
    }
    sort(v.begin(), v.end(), cmp); //不排序的话会错误
    for (int i = 0; i < v.size(); i++)
    {
        if (arr[v[i]] == 0)
        {
            if (flag == 1)
                cout << " ";
            cout << v[i];
            flag = 1;
        }
    }
    return 0;
}