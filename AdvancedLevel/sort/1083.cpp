#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    string name,id;
    int grade;
};
bool cmp(node a,node b)
{
    return a.grade>b.grade;
}
int main()
{
    int n;
    cin >> n;
    vector<node> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].name >> v[i].id >> v[i].grade;
    }
    int a,b;
    cin >> a >> b;
    vector<node> res;
    for(int i=0;i<n;i++){
        if(v[i].grade>=a && v[i].grade<=b){
            res.push_back(v[i]);
        }
    }
    sort(res.begin(),res.end(),cmp);
    for(int i=0;i<res.size();i++){
        cout << res[i].name << " " << res[i].id << endl;
    }
    if(res.size()==0) cout << "NONE\n";
    return 0;
}