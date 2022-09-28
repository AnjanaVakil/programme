#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <unordered_map>
using namespace std;
int main()
{
    // greedy
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int res = 1;
    int last = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] - last <= k)
        {
            continue;
        }
        res++;
        last = v[i];
    }
    cout << res << endl;
    return 0;
}