#include<iostream>
using namespace std;
int main()
{
    int n,m[4],a=0,b=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m[0] >> m[1] >> m[2] >> m[3];
        if(m[1]==m[0]+m[2] && m[1]!=m[3]){
            b++;
        }
        if(m[3]==m[0]+m[2] && m[1]!=m[3]){
            a++;
        }
    }
    cout << a << " " << b;
    return 0;
}