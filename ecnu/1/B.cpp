#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <unordered_map>
using namespace std;
bool cmp(string a, string b)
{
    return a + b > b + a;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    string res;
    for (int i = 0; i < n; i++)
    {
        res += v[i];
    }
    if (res[0] == '0')
    {
        cout << 0 << endl;
        return 0;
    }
    cout << res << endl;
    return 0;
}