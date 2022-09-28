#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // int a = n / 100, b = n / 10 % 10, c = n % 10;
    // for(int i=0;i<a;i++) cout << 'B';
    // for(int i=0;i<b;i++) cout << 'S';
    // for(int i=1;i<=c;i++) cout << i;

    int b[3]={0};
    int i=0;
    while(n!=0){
        b[i++]=n%10;
        n/=10;
    }
    for(int j=0;j<b[2];j++) cout << 'B';
    for(int j=0;j<b[1];j++) cout << 'S';
    for(int j=1;j<=b[0];j++) cout << j;

    return 0;
}