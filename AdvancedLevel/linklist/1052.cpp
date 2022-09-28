#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct Node{
    int address,key,next;
    bool flag;//结点是否在链表上
}node[maxn];
bool cmp(Node a,Node b)
{
    if(a.flag==false || b.flag==false){ //无效结点的处理
        return a.flag>b.flag;
    }else{
        return a.key<b.key;
    }
}
int main()
{
    for(int i=0;i<maxn;i++){
        node[i].flag=false;
    }
    int n,first,address;
    scanf("%d%d",&n,&first);
    // cin >> n >> first;
    for(int i=0;i<n;i++){
        scanf("%d",&address);
        scanf("%d%d",&node[address].key,&node[address].next);
        // scanf("%d%d%d",&address,&node[address].key,&node[address].next);
        //上面这条语句是错误的，scanf的话address还没读入再去写是错误的
        //用cin会超时
        // cin >> address >> node[address].key >> node[address].next;
        node[address].address=address;
    }
    int p=first,count=0;
    while(p!=-1){
        count++;
        node[p].flag=true;
        p=node[p].next;
    }
    if(count==0){
        printf("0 -1");
    }else{
        sort(node,node+maxn,cmp);
        //题目中可能有无效结点，所以要输出count，而不是直接输出n
        printf("%d %05d\n",count,node[0].address);
        for(int i=0;i<count;i++){
            if(i!=count-1){
                printf("%05d %d %05d\n",node[i].address,node[i].key,node[i+1].address);
            }else{
                printf("%05d %d -1\n",node[i].address,node[i].key);
            }
        }
    }
    return 0;   
}