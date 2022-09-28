#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct stu{
    string name;
    string id;
    int score;
};
bool cmp(stu a,stu b)
{
    return a.score>b.score;
}
int main()
{
    int n;
    cin >> n;
    vector<stu> v(n+1);
    for(int i=0;i<n;i++){
        cin >> v[i].name >> v[i].id >> v[i].score;
    }
    sort(v.begin(),v.end(),cmp);
    cout << v[0].name << " " << v[0].id << endl;
    cout << v[n-1].name << " " << v[n-1].id << endl;
    return 0;
}