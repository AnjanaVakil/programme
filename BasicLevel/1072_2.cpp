#include<iostream>
#include<algorithm>
using namespace std;
bool forbid[10000];
int main()
{
    int n,m,temp,k,snum=0,fnum=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> temp;
        forbid[temp]=true;
    }
    for(int i=0;i<n;i++){
        char name[10];
        bool flag=false;
        cin >> name >> k;
        for(int j=0;j<k;j++){
            cin >> temp;
            if(forbid[temp]){
                if(!flag){
                    cout << name << ":";
                    flag=true;
                }
                printf(" %04d",temp);
                fnum++;
            }
        }
        if(flag){
            cout << "\n";
            snum++;
        }
    }
    cout << snum << " " << fnum;
    return 0;
}