#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn=110;
vector<int> Node[maxn];
int hashTable[maxn];//记录每层的结点个数(当前level所含结点数)
int level[maxn];
void BFS(int root)
{
    queue<int> Q;
    Q.push(root);
    level[root]=1;
    while(!Q.empty()){
        int front=Q.front();
        Q.pop();
        //book[i]标记i层所拥有的结点数，在遍历的时候每弹出一个结点就将当前结点的层数所对应的book值+1
        hashTable[level[front]]++;
        for(int i=0;i<Node[front].size();i++){
            int child=Node[front][i];
            //数组level[i]标记i结点所处的层数，它等于它的父亲结点的level的值+1
            level[child]=level[front]+1;
            Q.push(child);
        }
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
    BFS(1);
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