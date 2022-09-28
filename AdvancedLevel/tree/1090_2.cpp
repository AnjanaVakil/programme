#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=100010;
struct node{
    vector<int> child;
    int layer;
}Node[maxn];
int maxLayer=-1,num;
int n;
double p,r;
void bfs(int index)
{
    queue<int> q;
    q.push(index);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        if(Node[front].child.size()==0){
            if(Node[front].layer>maxLayer){
                maxLayer=Node[front].layer;
                num=1;
            }else if(Node[front].layer==maxLayer){
                num++;
            }
        }
        for(int i=0;i<Node[front].child.size();i++){
            int childindex=Node[front].child[i];
            Node[childindex].layer=Node[front].layer+1;
            q.push(childindex);
        }
    }
}
int main()
{
    cin >> n >> p >> r;
    r/=100.0;
    int t,root;
    for(int i=0;i<n;i++){
        cin >> t;
        if(t==-1){
            root=i;
        }else{
            Node[t].child.push_back(i);
        }
    }
    bfs(root);
    printf("%.2f %d",p*pow(1+r,maxLayer),num);
    return 0;
}