#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template <class T>
void SelectSort(vector<T> &x)
{
    int n = x.size();
    int smallPos;
    for (int i = 0; i < n-1; i++)
    {
        smallPos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (x[j] < x[smallPos])
            {
                smallPos = j;
            }
        }
        if (j != smallPos)
        {
            swap(x[i], x[smallPos]);
        }
    }
}
