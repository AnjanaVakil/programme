#include<iostream>
using namespace std;
int main()
{
    string password,s;
    int n,i=0;
    cin >> password >> n;
    getchar();
    while(1){
        getline(cin,s);
        if(s=="#") break;
        if(i<n){
            if(s==password){
                cout << "Welcome in\n";
                break;
            }
            else{
                cout << "Wrong password: " << s << "\n";
                if(i==n-1){
                    cout << "Account locked\n";
                    break;
                }
            }
        }
        i++;
    }
    return 0;
}