#include<iostream>
using namespace std;
int main()
{
    int a,b,flag=0;
    while(cin >> a >> b){
        if(b!=0){
            if(flag) cout << " ";
            cout << a*b << " " << b-1;
            flag=1;
        }
    }
    if(!flag) cout << "0 0";
    return 0;
}