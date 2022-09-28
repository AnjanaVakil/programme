#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//25‘
const int maxn=100010;
struct Node{
    int data,next;
}node[maxn];
//v中分别保存的是符合条件的下标地址
vector<int> v[3];
int main()
{
    int first,n,k,addr,data;
    cin >> first >> n >> k;
    for(int i=0;i<n;i++){
        cin >> addr;
        cin >> node[addr].data >> node[addr].next;
    }
    int head=first;
    while(head!=-1){
        //下面的遍历必须在输入之后从first node开始遍历,否则就不是按照链表的顺序，是错误的
        if(node[head].data<0){
            v[0].push_back(head);
        }else if(node[head].data>=0 && node[head].data<=k){
            v[1].push_back(head);
        }else{
            v[2].push_back(head);
        }
        head=node[head].next;
    }
    int flag=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<v[i].size();j++){
            int index=v[i][j];
            if(flag==0){
                printf("%05d %d",index,node[index].data);
                flag=1;
            }else{
                printf(" %05d\n%05d %d",index,index,node[index].data);
            }
        }
    }
    printf(" -1\n");
    return 0;
}