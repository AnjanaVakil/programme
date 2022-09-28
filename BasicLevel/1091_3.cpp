#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin >> m;
    while(m--){
        cin >> n;
        int flag=0,count=1;
        for(int i=0;i<to_string(n).length();i++){
            count*=10;
        }
        for(int i=1;i<10;i++){
            //直接mul对count求余数其实就得到了末尾几位数
            if(i*n*n%count==n){
                flag=1;
                cout << i << " " << i*n*n << "\n";
                break;
            }
        }
        if(!flag){
            cout << "No\n";
        }
    }
    return 0;
}