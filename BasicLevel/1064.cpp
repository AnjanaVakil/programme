#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    int n;
    int a[100000]={0};
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        for(int j=0;j<v[i].length();j++){
            a[i]+=(v[i][j]-'0');
        }
    }
    set<int> s;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]==a[j]){
                s.insert(a[i]);
            }
        }
    }
    cout << s.size() << endl;
    for(auto it=s.begin();it!=s.end();it++){
        if(it!=s.begin()) cout << " ";
        cout << *it;
    }
    return 0;
}