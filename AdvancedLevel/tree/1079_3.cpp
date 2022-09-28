#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//25'
const int maxn=100010;
struct node{
    vector<int> child;
    int layer;
    int amount;
}Node[maxn];
double price;
int have[maxn];
double p,r;
void dfs(int index)
{
    if(Node[index].child.size()==0){
        price+=Node[index].amount*p*pow(1+r,Node[index].layer);
        return;
    }
    for(int i=0;i<Node[index].child.size();i++){
        int childindex=Node[index].child[i];
        Node[childindex].layer=Node[index].layer+1;
        dfs(childindex);
    }
}
int main()
{
    int n,k;
    cin >> n >> p >> r;
    r/=100.0;
    // vector<int> have(n,0);
    for(int i=0;i<n;i++){
        cin >> k;
        if(k!=0){
            int temp;
            for(int j=0;j<k;j++){
                cin >> temp;
                // have[temp]=1;
                Node[i].child.push_back(temp);
            }
        }else{
            cin >> Node[i].amount;
        }
    }
    // int root;
    // for(int i=0;i<n;i++){
    //     if(have[i]==0){
    //         root=i;
    //         break;
    //     }
    // }
    //the root supplier's ID is 0
    dfs(0);
    printf("%.1f",price);
    return 0;
}