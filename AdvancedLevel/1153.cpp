#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//这代码是真的写的很垃圾
struct student{
    string level;
    string site;
    string date;
    int score;
    string card;
};
struct site{
    string s;
    int count;
};
bool cmp2(site a,site b)
{
    if(a.count!=b.count) return a.count>b.count;
    else return a.s<b.s;
}
bool cmp(student a,student b)
{
    return a.score>b.score;
}
int main()
{
    int n,m;
    cin >> n >> m;
    string s;int score;
    vector<student> stu(n);
    for(int i=0;i<n;i++){
        cin >> s >> score;
        stu[i].card=s;
        stu[i].level=s.substr(0,1);
        stu[i].site=s.substr(1,3);
        stu[i].date=s.substr(4,6);
        stu[i].score=score;
    }
    int type;
    string query;
    for(int k=0;k<m;k++){
        cin >> type >> query;
        // cout << "Case " << i+1 << ": " << type << " " << query << "\n";
        printf("Case %d: %d %s\n",k+1,type,query.c_str());
        if(type==1){
            vector<student> v;
            for(int i=0;i<n;i++){
                if(stu[i].level==query){
                    v.push_back(stu[i]);
                }
            }
            sort(v.begin(),v.end(),cmp);
            for(int i=0;i<v.size();i++){
                cout << v[i].card << " " << v[i].score << "\n";
            }
            if(v.size()==0) cout << "NA\n";
        }else if(type==2){
            int count=0,sum=0;
            for(int i=0;i<n;i++){
                if(stu[i].site==query){
                    count++;
                    sum+=stu[i].score;
                }
            }
            if(count==0) cout << "NA\n";
            else{
                cout << count << " " << sum << "\n";
            }
        }else{
            vector<site> vsite;
            map<string,int> mapp;
            for(int i=0;i<n;i++){
                if(stu[i].date==query){
                    mapp[stu[i].site]++;
                }
            }
            for(auto it=mapp.begin();it!=mapp.end();it++){
                site t;
                t.s=it->first;
                t.count=it->second;
                vsite.push_back(t);
            }
            sort(vsite.begin(),vsite.end(),cmp2);
            for(int i=0;i<vsite.size();i++){
                cout << vsite[i].s << " " << vsite[i].count << "\n";
            }
            if(vsite.size()==0){
                cout << "NA\n";
            }
        }
    }
    return 0;
}