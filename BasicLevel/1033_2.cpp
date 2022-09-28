#include<iostream>
#include<cctype>
using namespace std;
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<b.length();i++){
        if(a.find(toupper(b[i]))!=string::npos) continue;
        if(isupper(b[i]) && a.find('+')!=string::npos) continue;
        cout << b[i];
    }
    return 0;
}