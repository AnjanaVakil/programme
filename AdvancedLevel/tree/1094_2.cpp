#include<iostream>
#include<vector>
using namespace std;
const int maxn=110;
vector<int> Node[maxn];
int hashTable[maxn];//记录每层的结点个数(当前level所含结点数)
void DFS(int index,int level)
{
    hashTable[level]++;
    for(int i=0;i<Node[index].size();i++){
        DFS(Node[index][i],level+1);
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    int father,k,child;
    for(int i=0;i<m;i++){
        cin >> father >> k;
        for(int j=0;j<k;j++){
            cin >> child;
            Node[father].push_back(child);
        }
    }
    DFS(1,1);
    int maxValue=0,maxLevel=-1;
    for(int i=0;i<maxn;i++){
        if(hashTable[i]>maxValue){
            maxValue=hashTable[i];
            maxLevel=i;
        }
    }
    cout << maxValue << " " << maxLevel;
    return 0;
}