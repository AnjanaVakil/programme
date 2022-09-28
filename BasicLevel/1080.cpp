#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
struct student{
    string id;
    int scoreP=-1,scoreM=-1,scoreF=-1,score=0;
};
bool cmp(student a,student b)
{
    if(a.score!=b.score) return a.score>b.score;
    else return a.id<b.id;
}
int main()
{
    int p,m,n,scoreP,scoreM,scoreF;
    cin >> p >> m >> n;
    map<string,student> ma;
    string id;
    vector<student> v;
    for(int i=0;i<p;i++){
        cin >> id >> scoreP;
        if(scoreP>=200){
            ma[id].id=id;
            ma[id].scoreP=scoreP;
        }
    }
    for(int i=0;i<m;i++){
        cin >> id >> scoreM;
        if(ma[id].scoreP>=200){
            ma[id].scoreM=scoreM;
        }
    }
    for(int i=0;i<n;i++){
        cin >> id >> scoreF;
        if(ma[id].scoreP>=200){
            ma[id].scoreF=scoreF;
        }
    }
    // for(map<string,student>::iterator it=ma.begin();it!=ma.end();it++){
    //     cout << it->first << " " << it->second.scoreP << " " << it->second.scoreM << " " << it->second.scoreF << " " << it->second.score << endl;
    // }
    for(map<string,student>::iterator it=ma.begin();it!=ma.end();it++){
        if(ma[it->first].scoreM>ma[it->first].scoreF){
            ma[it->first].score=(floor)(ma[it->first].scoreM*0.4+ma[it->first].scoreF*0.6+0.5);
        }else{
            ma[it->first].score=ma[it->first].scoreF;
        }
        if(ma[it->first].score>=60){
            v.push_back(it->second);
        }
    }
    // for(map<string,student>::iterator it=ma.begin();it!=ma.end();it++){
    //     cout << it->first << " " << it->second.scoreP << " " << it->second.scoreM << " " << it->second.scoreF << " " << it->second.score << endl;
    // }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cout << v[i].id << " ";
        cout << v[i].scoreP << " ";
        cout << v[i].scoreM << " ";
        cout << v[i].scoreF << " ";
        cout << v[i].score << endl;
    }
    return 0;
}