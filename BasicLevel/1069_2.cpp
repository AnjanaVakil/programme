#include <iostream>
#include <map>
using namespace std;
int main()
{
    int m, n, s,flag=0;
    cin >> m >> n >> s;
    string name;
    map<string,int> mapp;
    for(int i=1;i<=m;i++){
        cin >> name;
        if(mapp[name]==1) s=s+1;
        if(i==s && mapp[name]==0){
            mapp[name]=1;
            cout << name << endl;
            flag=1;
            s=s+n;
        }
    }
    if(flag==0) cout << "Keep going...";
    return 0;
}