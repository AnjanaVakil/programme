#include<iostream>
using namespace std;
const int maxn=100010;
struct Node{
    char data;
    int next;
    bool flag;
    // Node(){
    //     flag=false;
    // }
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
    for(int i=a;i!=-1;i=node[i].next){
        node[i].flag=true;
    }
    for(int i=b;i!=-1;i=node[i].next){
        if(node[i].flag==true){
            printf("%05d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}