#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int m,n,s;
    cin >> m >> n >> s;
    string name;
    vector<string> v(m+1);
    for(int i=1;i<=m;i++){
        cin >> v[i];
    }
    vector<string> res;
    for(int i=s;i<=m;){
        if(find(res.begin(),res.end(),v[i])==res.end()){
            res.push_back(v[i]);
            i+=n;
        }else{
            i++;
        }
    }
    for(int i=0;i<res.size();i++){
        cout << res[i] <<  "\n";
    }
    if(res.size()==0){
        cout << "Keep going...";
    }
    return 0;
}