#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//19:40-20:20 40min 25'
struct person{
    string id;
    int virtue,talent;
};
bool cmp(person a,person b)
{
    if(a.virtue+a.talent!=b.virtue+b.talent) 
        return a.virtue+a.talent>b.virtue+b.talent;
    else if(a.virtue!=b.virtue)
        return a.virtue>b.virtue;
    else 
        return a.id<b.id;
}
int main()
{
    int n,l,h;
    cin >> n >> l >> h;
    vector<person> sages,noble,fool,other;
    string id;
    int v,t;
    for(int i=0;i<n;i++){
        cin >> id >> v >> t;
        if(v>=l && t>=l){
            if(v>=h && t>=h){
            person p;
            p.id=id;
            p.virtue=v;
            p.talent=t;
            sages.push_back(p);
        }else if(v>=h && t<h){
            person p;
            p.id=id;
            p.virtue=v;
            p.talent=t;
            noble.push_back(p);
        }else if(v<h && t<h && v>=t){
            person p;
            p.id=id;
            p.virtue=v;
            p.talent=t;
            fool.push_back(p);
        }else{
            person p;
            p.id=id;
            p.virtue=v;
            p.talent=t;
            other.push_back(p);
        }
        }
    }
    sort(sages.begin(),sages.end(),cmp);
    sort(noble.begin(),noble.end(),cmp); 
    sort(fool.begin(),fool.end(),cmp);
    sort(other.begin(),other.end(),cmp);
    cout << sages.size()+noble.size()+fool.size()+other.size() << endl;
    for(int i=0;i<sages.size();i++){
        cout << sages[i].id << " " << sages[i].virtue << " " << sages[i].talent << "\n";
    }
    for(int i=0;i<noble.size();i++){
        cout << noble[i].id << " " << noble[i].virtue << " " << noble[i].talent << "\n";
    }
    for(int i=0;i<fool.size();i++){
        cout << fool[i].id << " " << fool[i].virtue << " " << fool[i].talent << "\n";
    }
    for(int i=0;i<other.size();i++){
        cout << other[i].id << " " << other[i].virtue << " " << other[i].talent << "\n";
    }
    return 0;
}