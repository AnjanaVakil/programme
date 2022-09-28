#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n,m,num;
    cin >> n;
    set<int> s[55];
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
        int nc=0,nt=s[b].size();
        for(set<int>::iterator it=s[a].begin();it!=s[a].end();it++){
            if(s[b].find(*it)==s[b].end()){
                //没找到
                nt++;
            }else{
                nc++;
            }
        }
        printf("%.1lf%%\n",(double)nc/nt*100);
    }
    return 0;
}