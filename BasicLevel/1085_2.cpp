#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
//测试的时候unordered_map和map都可以通过
using namespace std;
struct school{
    string name;
    double sum=0;
    int res=0;
    int cnt=0;
};
bool cmp(school a,school b)
{
    if(a.res!=b.res) return a.res>b.res;
    else if(a.cnt!=b.cnt) return a.cnt<b.cnt;
    else return a.name<b.name;
}
int main()
{
    int n,score;
    cin >> n;
    string id,s;
    unordered_map<string,school> m;
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
    vector<school> vec;
    for(unordered_map<string,school>::iterator it=m.begin();it!=m.end();it++){
        vec.push_back(school(it->second));
    }
    sort(vec.begin(),vec.end(),cmp);
    cout << vec.size() << endl;
    int rank=0,pres=-1;
    for(int i=0;i<vec.size();i++){
        if(pres!=vec[i].res) rank=i+1;
        pres=vec[i].res;
        cout << rank << " ";
        cout << vec[i].name << " " << vec[i].res << " " << vec[i].cnt << endl;
    }
    return 0;
}