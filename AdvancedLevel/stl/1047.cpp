#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
//17:45-18:05 18score
int main()
{
    int n,k;
    cin >> n >> k;
    map<int,set<string> > mapp;
    string name;
    int cnum,cou;
    for(int i=0;i<n;i++){
        cin >> name >> cnum;
        for(int j=0;j<cnum;j++){
            cin >> cou;
            mapp[cou].insert(name);
        }
    }
    for(auto it=mapp.begin();it!=mapp.end();it++){
        int cnt=mapp[it->first].size();
        cout << it->first << " " << cnt;
        for(set<string>::iterator it2=mapp[it->first].begin();it2!=mapp[it->first].end();it2++){
            cout << "\n";
            cout << *it2;
        }
        cout << "\n";
    }
    return 0;
}