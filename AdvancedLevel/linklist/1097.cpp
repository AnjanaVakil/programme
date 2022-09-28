#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct Node{
    int address,data,next;
    //c++11 编译不会有警告
    int order=2*maxn; //结点在链表上的序号
}node[maxn];
bool exist[maxn]={false};
bool cmp(Node a,Node b)
{
    return a.order<b.order;
}
int main()
{
    int n,first,address;
    cin >> first >> n;
    for(int i=0;i<n;i++){
        cin >> address;
        cin >> node[address].data >> node[address].next;
        node[address].address=address;
    }
    int cntValid=0,cntRemoved=0;
    for(int p=first;p!=-1;p=node[p].next){
        if(exist[abs(node[p].data)]==false){
            exist[abs(node[p].data)]=true;
            node[p].order=cntValid++;
        }else{
            node[p].order=maxn+cntRemoved++;
        }
    }
    sort(node,node+maxn,cmp);
    int cnt=cntValid+cntRemoved;
    for(int i=0;i<cnt;i++){
        if(i!=cntValid-1 && i!=cnt-1){
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        }else{
            printf("%05d %d -1\n",node[i].address,node[i].data);
        }
    }
    return 0;
}