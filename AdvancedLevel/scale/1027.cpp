#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{   
    char c[14]={"0123456789ABC"};
    cout << "#";
    for(int i=0;i<3;i++){
        int num;
        cin >> num;
        cout << c[num/13] << c[num%13];
    }
    return 0;
}