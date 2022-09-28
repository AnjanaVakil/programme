#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    //cnt:标记输出了多少个
    int m, n, num = 2, cnt = 0;
    cin >> m >> n;
    vector<int> v;
    while (cnt < n)
    {
        if (isPrime(num))
        {
            cnt++;
            if (cnt >= m)
            {
                v.push_back(num);
            }
        }
        num++;
    }
    cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cnt++;
        if (cnt % 10 != 1)
            cout << " ";
        cout << v[i];
        if (cnt % 10 == 0)
            cout << "\n";
    }
    return 0;
}