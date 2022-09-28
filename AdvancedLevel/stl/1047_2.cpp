#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//22score
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    map<int,vector<string> > mapp;
    string name;
    int cnum,cou;
    for(int i=0;i<n;i++){
        // cin >> name >> cnum;
        scanf("%s %d",&name,&cnum);
        for(int j=0;j<cnum;j++){
            scanf("%d",&cou);
            mapp[cou].push_back(name);
        }
    }
    for(auto it=mapp.begin();it!=mapp.end();it++){
        int cnt=mapp[it->first].size();
        printf("%d %d\n",it->first,cnt);
        // cout << it->first << " " << cnt << "\n";
        vector<string> v=mapp[it->first];
        sort(v.begin(),v.end());
        for(int j=0;j<v.size();j++){
            printf("%s\n",v[j].c_str());
        }
    }
    return 0;
}