#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        int z=stoi(s);
        int k=s.length()/2;
        string a=s.substr(0,k);
        string b=s.substr(k);
        int x=stoi(a);
        int y=stoi(b);
        //要注意a*b如果为0的时候不能取余，否则会浮点错误～
        // that Z can be devided by the product of A and B
        //Z可以被A和B的乘积整除
        if(x*y!=0 && z%(x*y)==0){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}