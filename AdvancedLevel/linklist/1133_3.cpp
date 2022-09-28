#include<iostream>
#include<algorithm>
using namespace std;
//22'
const int maxn=100010;
struct Node{
    int address,data,next;
    int index;
    int order;
}node[maxn];
bool cmp(Node a,Node b)
{
    if(a.index!=b.index){
        return a.index>b.index;
    }else{
        return a.order<b.order;
    }
}
int main()
{
    for(int i=0;i<maxn;i++){
        node[i].order=maxn;
    }
    int first,n,k,addr,data;
    cin >> first >> n >> k;
    for(int i=0;i<n;i++){
        cin >> addr;
        cin >> data >> node[addr].next;
        node[addr].address=addr;
        node[addr].data=data;
        if(data<0){
            node[addr].index=3;
        }else if(data>=0 && data<=k){
            node[addr].index=2;
        }else{
            node[addr].index=1;
        }
    }
    int count=0;
    int head=first;
    while(head!=-1){
        node[head].order=count;
        count++;
        head=node[head].next;
    }
    sort(node,node+maxn,cmp);
    printf("%05d %d",node[0].address,node[0].data);
    for(int i=1;i<count;i++){
        printf(" %05d\n%05d %d",node[i].address,node[i].address,node[i].data);
    }
    printf(" -1\n");
    return 0;
}