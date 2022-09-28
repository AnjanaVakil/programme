#include<iostream>
#include<vector>
using namespace std;
const int maxn=100010;
struct Node{
    int data,next;
};
Node node[maxn];
//v中分别保存的是符合条件的下标地址
vector<int> v[3];
int main()
{
    int first,n,k;
    cin >> first >> n >> k;
    int add;
    for(int i=0;i<n;i++){
        //注意:这里不能连写，否则段错误 0‘
        cin >> add;
        cin >> node[add].data >> node[add].next;
    }
    int index=first;
    while(index!=-1){
        if(node[index].data<0){
            v[0].push_back(index);
        }else if(node[index].data>=0 && node[index].data<=k){
            v[1].push_back(index);
        }else{
            v[2].push_back(index);
        }
        index=node[index].next;
    }
    int flag=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<v[i].size();j++){
            index=v[i][j];
            if(flag){
                printf("%05d %d",index,node[index].data);
                flag=0;
            }else{
                printf(" %05d\n%05d %d",index,index,node[index].data);
            }
        }
    }
    printf(" -1\n");
    return 0;
}