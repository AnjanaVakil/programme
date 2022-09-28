#include<iostream>
using namespace std;
bool isEqual(int a,int b)
{
    while(a && b){
        if(a%10 != b%10) return false;
        a/=10;
        b/=10;
    }
    return true;
}
int main()
{
    int m,n,t;
    cin >> m;
    while(m--){
        cin >> n;
        int flag=0;
        for(int i=1;i<10;i++){
            //要善用函数,不要让自己的代码很累赘
            int mul=i*n*n;
            if(isEqual(n,mul)){
                cout << i << " " << mul << "\n";
                flag=1;
                break;
            }
        }
        if(!flag){
            cout << "No\n";
        }
    }
    return 0;
}