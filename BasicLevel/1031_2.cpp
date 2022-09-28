#include<iostream>
using namespace std;
int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int m[11] = {1, 0, 40, 9, 8, 7, 6, 5, 4, 3, 2};
string s; //s是全局变量
bool isTrue()
{
    int z=0;
    for(int i=0;i<17;i++){
        if(s[i]<'0' || s[i]>'9') return false;
        z+=(s[i]-'0')*weight[i];
    }
    return (s[17]-'0')==m[z%11];
}
int main()
{
    int n,flag=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        if(!isTrue()){
            cout << s << endl;
            flag=1;
        }
    }
    if(flag==0){
        cout << "All passed";
    }
    return 0;
}