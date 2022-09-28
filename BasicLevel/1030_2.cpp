#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int N;
    //p（≤10^9）
    //每个数不超过 10^9
    //相乘的结果可能会溢出int,所以p设为long long
    long long p;
    cin >> N >> p;
    //每个数不超过 10^9,所以vector可以设为int
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    //10 8
    //2 3 20 4 5 1 6 7 8 9
    //1 2 3 4 5 6 7 8 9 20
    //设当前结果为result = 0，当前最长长度为temp = 0
    int result = 0, temp = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + result; j < N; j++)
        {
            if (v[j] <= v[i] * p)
            {
                temp = j - i + 1;
                if (temp > result)
                    result = temp;
            }
            else
            {
                break;
            }
        }
    }
    cout << result;
    return 0;
}