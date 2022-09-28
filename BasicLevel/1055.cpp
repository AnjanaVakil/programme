#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct people
{
    string name;
    int height;
};
people peo[10000 + 5];
bool cmp(people a, people b)
{
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> peo[i].name >> peo[i].height;
    }
    sort(peo, peo + N, cmp);
    // for(int i=0;i<N;i++){
    //     cout << peo[i].name << " " << peo[i].height << endl;
    // }
    int per = N / K;
    int last = per + N % K;
    vector<string> lastv(last);
    int i = 0;
    //中间位置为 m/2+1 
    //但是数组下标从0开始，所以其实还是 m/2
    lastv[last / 2] = peo[i++].name;
    int j = last / 2 - 1, k = last / 2 + 1;
    while (j >= 0 && k <= last - 1)
    {
        lastv[j--] = peo[i++].name;
        lastv[k++] = peo[i++].name;
    }
    while (j >= 0)
    {
        lastv[j--] = peo[i++].name;
    }
    while (k <= last - 1)
    {
        lastv[k++] = peo[i++].name;
    }
    for (int t = 0; t < last; t++)
    {
        cout << lastv[t];
        if (t != last - 1)
            printf(" ");
        else
            printf("\n");
    }
    for (int t = 0; t < K - 1; t++)
    {
        vector<string> perv(per);
        perv[per / 2] = peo[i++].name;
        j = per / 2 - 1, k = per / 2 + 1;
        while (j >= 0 && k <= per - 1)
        {
            perv[j--] = peo[i++].name;
            perv[k++] = peo[i++].name;
        }
        while (j >= 0)
        {
            perv[j--] = peo[i++].name;
        }
        while (k <= per - 1)
        {
            perv[k++] = peo[i++].name;
        }
        for (int t2 = 0; t2 < per; t2++)
        {
            cout << perv[t2];
            if (t2 != per - 1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}