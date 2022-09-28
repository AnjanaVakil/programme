#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <unordered_map>
#include <stdio.h>
#include <time.h>
using namespace std;
clock_t start, stop;
double duration;
void selectSort1(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        int minIndex = i; // 无序区的最小数据数组下标
        for (int j = i + 1; j < a.size(); j++)
            // 在无序区中找到最小数据并保存其数组下标
            if (a[j] < a[minIndex])
                minIndex = j;
        int t = a[i];
        a[i] = a[minIndex];
        a[minIndex] = t;
    }
}
void selectSort2(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    }
}
int main()
{
    int n = 1e3;
    vector<int> a(n + 1);
    for (int i = n; i >= 1; i--)
    {
        a.push_back(i);
    }
    start = clock();
    selectSort1(a);
    stop = clock();
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    cout << duration << endl;

    vector<int> b(n + 1);
    for (int i = n; i >= 1; i--)
    {
        b.push_back(i);
    }
    start = clock();
    selectSort2(b);
    stop = clock();
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    cout << duration << endl;
    return 0;
}