#include <iostream>
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
//会有运行超时的问题
//求第i个素数
int prime(int i)
{
    int k = 0, num = 2, value;
    while (k < i)
    {
        if (isPrime(num))
        {
            k++;
            value = num;
        }
        num++;
    }
    return value;
}
int main()
{
    int m, n, pm, pn;
    cin >> m >> n;
    int cnt = 0;
    for (int i = prime(m); i <= prime(n); i++)
    {
        //太麻烦,运行超时
        //应该在判断第m到第n个素数的时候将中间结果记录下来
        if (isPrime(i))
        {
            cnt++;
            if (cnt % 10 != 1)
                cout << " ";
            cout << i;
            if (cnt % 10 == 0)
                cout << "\n";
        }
    }
    return 0;
}