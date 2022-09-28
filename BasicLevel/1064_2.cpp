#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> v[i];
        int t=0;
        for(int j=0;j<v[i].length();j++){
            t+=(v[i][j]-'0');
        }
        s.insert(t);
    }
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         //仔细看你写的这个代码，就会发现数组a完全没有必要
    //         //直接存储到s中就行，因为set是有序的，不重复的
    //         if(a[i]==a[j]){
    //             s.insert(a[i]);
    //         }
    //     }
    // }
    cout << s.size() << endl;
    for(auto it=s.begin();it!=s.end();it++){
        if(it!=s.begin()) cout << " ";
        cout << *it;
    }
    return 0;
}