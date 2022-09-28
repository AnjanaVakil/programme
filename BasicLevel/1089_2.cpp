#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    //隐含条件:有 2 人说的不是实话，有狼人撒谎但并不是所有狼人都在撒谎
    //说明:说谎人数等于2并且这两个说谎的人一个是好人一个是狼人
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            //a数组表示该人是狼人还是好人，等于1表示是好人，等于-1表示是狼人
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++)
            {
                if (v[k] * a[abs(v[k])] < 0)
                {
                    lie.push_back(k);
                }
            }
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0)
            {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}