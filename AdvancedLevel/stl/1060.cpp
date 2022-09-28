#include<iostream>
using namespace std;
//9:22-9:40 17'
int main()
{
    int n;
    string a,b;
    cin >> n >> a >> b;
    string res1="0.",res2="0.";
    string sign1=a.substr(0,n);
    // cout << sign1 << endl;
    string sign2=b.substr(0,n);
    // cout << sign2 << endl;
    res1+=sign1;
    res1+="*10^";
    res1+=to_string(a.length());
    if(sign1==sign2){
        cout << "YES ";
        cout << res1;
        return 0;
    }
    res2+=sign2;
    res2+="*10^";
    res2+=to_string(b.length());
    cout << "NO " << res1 << " " << res2;
    return 0;
}