#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
//05-44 22'
struct school{
    string name;
    double tws;
    int ns,rank;
};
bool cmp(school a,school b)
{
    if(a.tws!=b.tws) return a.tws>b.tws;
    else if(a.ns!=b.ns) return a.ns<b.ns;
    else return a.name<b.name;
}
int main()
{
    int n;
    cin >> n;
    unordered_map<string,school> mp;
    string id,sch;
    int score;
    for(int i=0;i<n;i++){
        cin >> id >> score >> sch;
        for(int j=0;j<sch.length();j++){
            sch[j]=tolower(sch[j]);
        }
        mp[sch].name=sch;
        if(id[0]=='A'){
            mp[sch].tws+=score;
        }else if(id[0]=='B'){
            mp[sch].tws+=score/1.5;
        }else{
            mp[sch].tws+=score*1.5;
        }
        mp[sch].ns++;
    }
    vector<school> v;
    for(auto it=mp.begin();it!=mp.end();it++){
        v.push_back(it->second);
    }
    sort(v.begin(),v.end(),cmp);
    v[0].rank=1;
    for(int i=1;i<n;i++){
        if((int)v[i].tws==(int)v[i-1].tws){
            v[i].rank=v[i-1].rank;
        }else{
            v[i].rank=i+1;
        }
    }
    cout << (int)v.size() << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i].rank << " " << v[i].name << " " << (int)v[i].tws << " " << v[i].ns << endl;
    }
    return 0;
}