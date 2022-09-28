#include <iostream>
#include <queue>
using namespace std;
int flag[100];
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    queue<char> q;
    for (int i = 0; i < a.length(); i++)
    {
        if (flag[a[i]] == 0)
        {
            q.push(a[i]);
            flag[a[i]] = 1;
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (flag[b[i]] == 0)
        {
            q.push(b[i]);
            flag[b[i]] = 1;
        }
    }
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    return 0;
}