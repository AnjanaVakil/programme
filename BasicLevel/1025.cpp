#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct list
{
    int address;
    int data;
    int next;
};
int main()
{
    int start, n, k;
    cin >> start >> n >> k;
    list v[100001], vec[100001];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].address >> v[i].data >> v[i].next;
    }
    for (int i = 0; i < n; i++)
    {
        vec[i] = v[start];
        start = vec[i].next;
        if (start == -1)
        {
            n = i + 1; //可能有无效节点,更新链表中节点的数量
            break;
        }
    }
    for (int i = 0; i < (n / k); i++)
    {
        for (int j = 0; j < k / 2; j++)
        {
            list temp;
            temp = vec[j + i * k];
            vec[j + i * k] = vec[k - 1 - j + i * k];
            vec[k - 1 - j + i * k] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            vec[i].next = vec[i + 1].address;
            printf("%05d %d %05d\n", vec[i].address, vec[i].data, vec[i].next);
        }
        else
        {
            vec[i].next = -1;
            printf("%05d %d %d\n", vec[i].address, vec[i].data, vec[i].next);
        }
    }
    return 0;
}