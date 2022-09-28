#include<iostream>
#include<vector>
#include<set>
using namespace std;
//21:00-25 0score 说明方法错误，应该立马换一种思路
set<int> s[55];
int main()
{
    int n,m,num;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> m;
        for(int j=0;j<m;j++){
            cin >> num;
            s[i].insert(num);
        }
    }
    int k,a,b;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> a >> b;
        int t=s[a].size()+s[b].size();
        for(set<int>::iterator it=s[a].begin();it!=s[a].end();it++){
            s[b].insert(*it);
        }
        int com=t-s[b].size();
        printf("%.1lf%%\n",(double)com/s[b].size()*100.0);
    }
    return 0;
}