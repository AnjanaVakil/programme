#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]>max){
            max=a[i];
            s.insert(a[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]<min){
            min=a[i];
        }else{
            s.erase(a[i]);
        }
    }
    cout << s.size() << "\n";
    for(auto it=s.begin();it!=s.end();it++){
        if(it!=s.begin()) cout << " ";
        cout << *it;
    }
    cout << "\n";
    return 0;
}