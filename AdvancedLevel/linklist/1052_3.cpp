#include<iostream>
#include<algorithm>
using namespace std;
//25'
const int maxn=100010;
struct Node{
    int address,data,next;
    bool flag;
}node[maxn];
bool cmp(Node a,Node b)
{
    if(a.flag==false || b.flag==false){
        return a.flag>b.flag;
    }else{
        return a.data<b.data;
    }
}
int main()
{
    int n,head,add;
    cin >> n >> head;
    for(int i=0;i<n;i++){
        cin >> add;
        cin >> node[add].data >> node[add].next;
        node[add].address=add;
    }
    int len=0;
    while(head!=-1){
        node[head].flag=true;
        len++;
        head=node[head].next;
    }
    if(len==0){
        printf("0 -1");
    }else{
        sort(node,node+maxn,cmp);
        printf("%d %05d\n",len,node[0].address);
        for(int i=0;i<len;i++){
            if(i==len-1){
                printf("%05d %d -1\n",node[i].address,node[i].data);
            }else{
                printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
            }
        }
    }
    return 0;
}