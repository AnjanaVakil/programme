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
    }
    return a.key<b.key;
}
int main()
{
    int n,first,address;
    scanf("%d%d",&n,&first);
    int a,b,c;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        //使用c++11可以编译通过
        node[a]={a,b,c,false};
    }
    int count=0;
    for(int i=first;i!=-1;i=node[i].next){
        node[i].flag=true;
        count++;
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