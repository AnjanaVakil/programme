#include<iostream>
#include<algorithm>
using namespace std;
//还是不会写
const int maxn=100010;
struct Node{
    int address,data,next;
    int order;
};
Node node[maxn];
bool cmp(Node a,Node b)
{
    return a.order<b.order;
}
int main()
{
    for(int i=0;i<maxn;i++){
        node[i].order=maxn;
    }
    int first,n,k,address;
    cin >> first >> n >> k;
    for(int i=0;i<n;i++){
        cin >> address;
        cin >> node[address].data >> node[address].next;
        node[address].address=address;
    }
    int p=first,count=0;
    while(p!=-1){
        node[p].order=count++;
        p=node[p].next;
    }
    sort(node,node+maxn,cmp);
    n=count;
    for(int i=0;i<n/k;i++){
        for(int j=(i+1)*k-1;j>i*k;j--){
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
        }
        printf("%05d %d ",node[i*k].address,node[i*k].data);
        if(i<n/k-1){
            printf("%05d\n",node[(i+2)*k-1].address);
        }else{
            if(n%k==0){
                printf("-1\n");
            }else{
                printf("%05d\n",node[(i+1)*k].address);
                for(int i=n/k*k;i<n;i++){
                    printf("%05d %d ",node[i].address,node[i].data);
                    if(i<n-1){
                        printf("%05d\n",node[i+1].address);
                    }else{
                        printf("-1\n");
                    }
                }
            }
        }
    }
    return 0;
}