#include<iostream>
using namespace std;
const int maxn=100010;
struct Node{
    char data;
    int next;
    bool flag;
}node[maxn];
//25'
int main()
{
    for(int i=0;i<maxn;i++){
        node[i].flag=false;
    }
    int a,b,n,address;
    cin >> a >> b >> n;
    for(int i=0;i<n;i++){
       cin >> address;
       cin >> node[address].data >> node[address].next;
    }
    while(a!=-1){
        node[a].flag=1;
        a=node[a].next;
    }
    while(b!=-1){
        if(node[b].flag==1){
            printf("%05d",b);
            return 0;
        }
        b=node[b].next;
    }
    if(b==-1){
        printf("-1");
    }
    return 0;
}