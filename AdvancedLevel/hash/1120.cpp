#include<iostream>
#include<vector>
#include<set>
using namespace std;
//16:44-16:56 12min AC
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> res;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<v.size();i++){
        int sum=0;
        while(v[i]){
            sum+=(v[i]%10);
            v[i]/=10;
        }
        res.insert(sum);
    }
    cout << res.size() << endl;
    for(auto it=res.begin();it!=res.end();it++){
        if(it!=res.begin()) cout << " ";
        cout << *it;
    }
    return 0;
}