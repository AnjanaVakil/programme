#include<iostream>
using namespace std;
int main()
{
    int n;
    char c;
    cin >> n >> c;
    for(int i=0;i<n;i++){
        cout << c;
    }
    cout << endl;
    //四舍五入取整
    //int temp=(n%2==0)?n/2:n/2+1;
    int temp=n/2+n%2;
    for(int i=0;i<temp-2;i++){
        cout << c;
        for(int j=0;j<n-2;j++){
            cout << " ";
        }
        cout << c << "\n";
    }
    for(int i=0;i<n;i++){
        cout << c;
    }
    return 0;
}