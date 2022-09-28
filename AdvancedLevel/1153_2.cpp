#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//还是要先读题，再写代码，否则很容易按照自己主观臆断的来写，很容易写错
struct node{
    string t;
    int value;
};
bool cmp(node a,node b)
{
    if(a.value!=b.value) return a.value>b.value;
    else return a.t<b.t;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<node> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].t >> v[i].value;
    }
    int type;
    string query;
    for(int k=1;k<=m;k++){
        cin >> type >> query;
        vector<node> ans;
        printf("Case %d: %d %s\n",k,type,query.c_str());
        int count=0,sum=0;
        if(type==1){
            for(int i=0;i<n;i++){
                if(v[i].t[0]==query[0]){
                    ans.push_back(v[i]);
                }
            }
        }else if(type==2){
            for(int i=0;i<n;i++){
                if(v[i].t.substr(1,3)==query){
                    count++;
                    sum+=v[i].value;
                }
            }
            if(count!=0) cout << count << " " << sum << "\n";
        }else{
            unordered_map<string,int> mapp;
            for(int i=0;i<n;i++){
                if(v[i].t.substr(4,6)==query){
                    mapp[v[i].t.substr(1,3)]++;
                }
            }
            for(auto it:mapp){
                ans.push_back({it.first,it.second});
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<ans.size();i++){
            cout << ans[i].t << " " << ans[i].value << "\n";
        }
        if(((type==1 || type==3) && ans.size()==0) || (type==2 && count==0)){
            cout << "NA\n";
        }
    }
    return 0;
}