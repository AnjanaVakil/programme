#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int z;
    for(int i=0;i<n;i++){
        cin >> z;
        string s=to_string(z);
        int k=s.length()/2;
        string a=s.substr(0,k);
        string b=s.substr(k);
        int x=stoi(a);
        int y=stoi(b);
        if(x*y!=0 && z%(x*y)==0){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}