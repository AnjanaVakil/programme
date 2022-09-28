#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin >> m;
    while(m--){
        cin >> n;
        int flag=0;
        for(int i=1;i<10;i++){
            string a=to_string(n),b=to_string(i*n*n);
            string str=b.substr(b.length()-a.length());
            if(a==str){
                cout << i << " " << b << endl;
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