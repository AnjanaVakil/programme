#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    int m,n,k;
    cin >> m >> n >> k;
    for(int i=0;i<k;i++){
        stack<int> s;
        vector<int> v(n+1);
        bool flag=false;
        int current=1;
        for(int j=1;j<=n;j++){
            cin >> v[j];
        }
        for(int j=1;j<=n;j++){
            s.push(j);
            if(s.size()>m){
                break;
            }
            while(!s.empty() && s.top()==v[current]){
                s.pop();
                current++;
            }
        }
        if(current==n+1) flag=true;
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}