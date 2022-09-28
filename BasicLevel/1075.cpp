#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct node{
    int num,next;
}list[100000];
int main()
{
    int n,k,start,front,rear;
    cin >> start >> n >> k;
    for(int i=0;i<n;i++){
        cin >> front;
        cin >> list[front].num >> list[front].next;
    }
    vector<int> v[3];
    int p=start;
    while(p!=-1){
        int data=list[p].num;
        if(data<0) v[0].push_back(p);
        else if(data>=0 && data<=k) v[1].push_back(p);
        else v[2].push_back(p);
        p=list[p].next;
    }
    int flag=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<v[i].size();j++){
            if(flag==0){
                printf("%05d %d ",v[i][j],list[v[i][j]].num);
                flag=1;
            }else {
                printf("%05d\n%05d %d ",v[i][j],v[i][j],list[v[i][j]].num);
            }
        }
    }
    printf("-1");
    return 0;
}