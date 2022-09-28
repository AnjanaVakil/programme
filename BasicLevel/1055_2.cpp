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
    //如果身高不等，就按照身高从大到小排列；如果身高相等，就按照名字从小到大的字典序排列
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
    int t=0,row=K,m;
    while(row){
        //m每一行的人数
        // if(row==K) m=N-N/K*(K-1);//第一行的人数m=N/K+N%K;
        if(row==K) m=N/K+N%K;//第一行的人数m=N/K+N%K;
        else m=N/K;
        vector<string> ans(m);
        ans[m/2]=peo[t].name;
        int j=m/2-1;
        for(int i=t+1;i<t+m;i+=2){
            ans[j--]=peo[i].name;
        }
        j=m/2+1;
        for(int i=t+2;i<t+m;i+=2){
            ans[j++]=peo[i].name;
        }
        cout << ans[0];
        for(int i=1;i<m;i++){
            cout << " " << ans[i];
        }
        cout << endl;
        t=t+m;
        row--;
    }
    return 0;
}