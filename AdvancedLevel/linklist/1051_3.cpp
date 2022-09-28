//17- 还是不会写
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int cap,n,k,num;
    cin >> cap >> n >> k;
    for(int i=0;i<k;i++){
        //初始化应该放到循环里面
        stack<int> s;
        int a[1010];    
        bool flag=false;
        int current=1;
        for(int j=1;j<=n;j++){
            cin >> a[j];
        }
        for(int j=1;j<=n;j++){
            s.push(j);
            if(s.size()>cap){
                break;
            }
            while(!s.empty() && s.top()==a[current]){
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