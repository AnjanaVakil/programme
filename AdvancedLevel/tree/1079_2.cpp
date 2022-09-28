#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const int maxn=100010;
struct node{
    double amount;
    vector<int> child;
    int layer; //记录层号
}Node[maxn];
int n;
double p,r,ans=0.0;
//BFS 层序遍历
void BFS(int root)
{
    queue<int> Q;
    Q.push(root);
    Node[root].layer=0;
    while(!Q.empty()){
        int front=Q.front();
        //访问当前结点即叶结点的数据域amount,layer
        if(Node[front].child.size()==0){
            ans+=Node[front].amount*pow(1+r,Node[front].layer);
        }
        Q.pop();
        for(int i=0;i<Node[front].child.size();i++){
            int child=Node[front].child[i];
            Node[child].layer=Node[front].layer+1;
            Q.push(child);
        }
    }
}
int main()
{
    cin >> n >> p >> r;
    r/=100;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        if(k!=0){
            for(int j=0;j<k;j++){
                int id;
                cin >> id;
                Node[i].child.push_back(id);
            }
        }else{
            cin >> Node[i].amount;
        }
    }
    BFS(0);
    printf("%.1f",p*ans);
    return 0;
}