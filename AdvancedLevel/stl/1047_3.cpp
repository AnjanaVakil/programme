#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//22score
int main()
{
    int n,k;
    cin >> n >> k;
    map<int,vector<string> > mapp;
    string name;
    int cnum,cou;
    for(int i=0;i<n;i++){
        cin >> name >> cnum;
        for(int j=0;j<cnum;j++){
            cin >> cou;
            mapp[cou].push_back(name);
        }
    }
    for(auto it=mapp.begin();it!=mapp.end();it++){
        int cnt=mapp[it->first].size();
        cout << it->first << " " << cnt;
        sort(mapp[it->first].begin(),mapp[it->first].end());
        for(int j=0;j<cnt;j++){
            cout << "\n";
            cout << mapp[it->first][j];
        }
        cout << "\n";
    }
    return 0;
}