#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// 题目没看懂自己也不会写
struct mouse{
    int weight;
    int rank;
};
int main()
{
    int n,group;
    cin >> n >> group;
    vector<mouse> mou(1010);
    queue<int> q;
    for(int i=0;i<n;i++){
        cin >> mou[i].weight;
    }
    int order;
    for(int i=0;i<n;i++){
        cin >> order;
        q.push(order);
    }
    int temp=n,groupnum;
    while(q.size()!=1){
        //能够完整划分
        if(temp%group==0){
            groupnum=temp/group;
        }else{
            groupnum=temp/group+1;
        }
        for(int i=0;i<groupnum;i++){
            int k=q.front();
            for(int j=0;j<group;j++){
                if(i*group+j>=temp) break;
                int front=q.front();
                if(mou[front].weight>mou[k].weight){
                    k=front;
                }
                mou[front].rank=groupnum+1;
                q.pop();
            }
            q.push(k);
        }
        temp=groupnum;
    }
    mou[q.front()].rank=1;
    for(int i=0;i<n;i++){
        cout << mou[i].rank;
        if(i<n-1) cout << " ";
    }
    return 0;
}