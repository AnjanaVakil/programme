#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//19'
struct node{
    string id;
    int pr,mid,fin;
    int grade;
};
bool cmp(node a,node b)
{
    if(a.grade!=b.grade) return a.grade>b.grade;
    else return a.id<b.id;
}
int main()
{
    int p,m,n;
    cin >> p >> m >> n;
    vector<node> v;
    map<string,node> mp;
    string id;
    int score;
    for(int i=0;i<p;i++){
        cin >> id >> score;
        if(score>=200){
            mp[id].id=id;
            mp[id].pr=score;
        }
    }
    for(int i=0;i<m;i++){
        cin >> id >> score;
        mp[id].id=id;
        mp[id].mid=score;
    }
    for(int i=0;i<n;i++){
        cin >> id >> score;
        mp[id].id=id;
        mp[id].fin=score;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        v.push_back(it->second);
    }
    for(int i=0;i<v.size();i++){
        if(v[i].mid>v[i].fin){
            //四舍五入这里需要加0.5
            v[i].grade=(int)(v[i].mid*0.4+v[i].fin*0.6+0.5);
        }else{
            v[i].grade=v[i].fin;
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        if(v[i].grade>=60 && v[i].pr!=0){
            cout << v[i].id << " " << v[i].pr << " ";
            if(v[i].mid==0){
                cout << "-1 ";
            }else{
                cout << v[i].mid << " ";
            }
            if(v[i].fin==0){
                cout << "-1 ";
            }else{
                cout << v[i].fin << " ";
            }
            cout << v[i].grade << "\n";
        }
    }
    return 0;
}