#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//21score 测试点3运行超时
int main()
{
    int n,m;
    scanf("%d",&n);
    string a,b;
    map<string,string> mapp;
    for(int i=0;i<n;i++){
        // scanf("%s%s",&a,&b);
        cin >> a >> b;
        mapp[a]=b;
        mapp[b]=a;
    }
    scanf("%d",&m);
    vector<string> v(m);
    vector<string> res;
    for(int i=0;i<m;i++){
        // scanf("%s",&v[i]);
        cin >> v[i];
    }
    for(int i=0;i<m;i++){
        if(mapp.find(v[i])==mapp.end()){
            res.push_back(v[i]);
        }else{
            //没找到
            if( find(v.begin(),v.end(),mapp[v[i]])==v.end() ){
                res.push_back(v[i]);
            }
        }
    }
    cout << res.size() << endl;
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        if(i!=0) cout << " ";
        cout << res[i];
    }
    return 0;
}