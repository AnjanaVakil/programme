#include <iostream>
#include <map>
using namespace std;
int main()
{
    int m,n,s,flag=0;
    cin >> m >> n >> s;
    string str;
    map<string,int> mapp;
    for(int i=1;i<=m;i++){
        cin >> str;
        if(mapp[str]==1) s+=1;
        if(i==s && mapp[str]==0){
            mapp[str]=1;
            cout << str << endl;
            flag=1;
            s=s+n;
        }
    }
    if(flag==0) cout << "Keep going...";
    return 0;
}