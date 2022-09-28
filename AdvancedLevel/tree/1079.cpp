#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
struct node{
    double amount;
    vector<int> child;
}Node[maxn];
int n;
double p,r,ans=0.0;
//DFS 先根遍历
void DFS(int index,int depth)
{
    if(Node[index].child.size()==0){//递归边界：到达叶结点
        ans+=Node[index].amount*pow(1+r,depth);
        return;
    }
    for(int i=0;i<Node[index].child.size();i++){
        DFS(Node[index].child[i],depth+1);
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
    DFS(0,0);
    printf("%.1f",p*ans);
    return 0;
}