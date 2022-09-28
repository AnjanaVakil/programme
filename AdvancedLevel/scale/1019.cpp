//17:33-43 20'
#include<iostream>
using namespace std;
bool isPalin(int a[],int n)
{
    for(int i=0;i<n/2;i++){
        if(a[i]!=a[n-i-1]){
            return false;
        }
    }
    return true;
}
int main()
{
    int n,b,z[32],num=0;
    cin >> n >> b;
    do{
        z[num++]=n%b;
        n/=b;
    }while(n!=0);
    if(isPalin(z,num)){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    for(int i=num-1;i>=0;i--){
        cout << z[i];
        if(i!=0) cout << " ";
    }
    return 0;
}