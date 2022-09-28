#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n,num;
    cin >> n;
    map<int,int> hash;
    for(int i=0;i<n;i++){
        cin >> num;
        hash[num]=1;
    }
    for(int i=1;;i++){
        if(hash[i]==0){
            cout << i;
            break;
        }
    }
    return 0;
}