#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct school{
    string name;
    double sum=0;
    int res=0;
    int cnt=0;
};
bool cmp(pair<string,school> a,pair<string,school> b)
{
    if(a.second.res!=b.second.res) return a.second.res>b.second.res;
    else if(a.second.cnt!=b.second.cnt) return a.second.cnt<b.second.cnt;
    else return a.second.name<b.second.name;
}
int main()
{
    int n,score;
    cin >> n;
    string id,s;
    map<string,school> m;
    for(int i=0;i<n;i++){
        cin >> id >> score >> s;
        for(int i=0;i<s.length();i++){
            if(isupper(s[i])) s[i]=tolower(s[i]);
        }
        m[s].name=s;
        if(id[0]=='B'){
            m[s].sum+=score/1.5;
        }else if(id[0]=='A'){
            m[s].sum+=score;
        }else{
            m[s].sum+=score*1.5;
        }
        m[s].res=(int)m[s].sum;
        m[s].cnt++;
    }
    // sort(m.begin(),m.end());
    //map默认是按key值从小到大排序的
    //按value值排序：
    //想直接用sort排序是做不到的，sort只支持数组、vetctor等的排序，
    //所以我们可以先把map装进pair里，然后再放入vector，自定义sort实现排序
    // for(auto it:m){
    //     cout << it.first << " " << it.second.res << " " << it.second.cnt << endl;
    // }
    vector< pair<string,school> > vec;
    for(map<string,school>::iterator it=m.begin();it!=m.end();it++){
        vec.push_back( pair<string,school>(it->first,it->second));
    }
    sort(vec.begin(),vec.end(),cmp);
    cout << vec.size() << endl;
    int count=1,pres=-1;
    for(int i=0;i<vec.size();i++){
        if(pres!=vec[i].second.res) count=i+1;
        pres=vec[i].second.res;
        cout << count << " ";
        cout << vec[i].first << " " << vec[i].second.res << " " << vec[i].second.cnt << endl;
    }
    return 0;
}