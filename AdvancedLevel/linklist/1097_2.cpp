#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct Node{
    int address,data,next;
    int order=maxn*2;
}node[maxn];
int book[maxn];
bool cmp(Node a,Node b)
{
    return a.order<b.order;
}
int main()
{
    int first,n,addr;
    cin >> first >> n;
    for(int i=0;i<n;i++){
        cin >> addr;
        cin >> node[addr].data >> node[addr].next;
        node[addr].address=addr;
    }
    int p=first,cntV=0,cntR=0;
    while(p!=-1){
        int absValue=abs(node[p].data);
        if(book[absValue]==0){
            node[p].order=cntV++;
        }else{
            node[p].order=maxn+cntR++;
        }
        book[absValue]=1;
        p=node[p].next;
    }
    sort(node,node+maxn,cmp);
    int cnt=cntV+cntR;
    int flag=1;
    for(int i=0;i<cnt;i++){
        if(i!=cntV-1 && i!=cnt-1){
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        }else{
            printf("%05d %d -1\n",node[i].address,node[i].data);
        }
    }
    return 0;
}