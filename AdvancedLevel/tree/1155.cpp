#include<iostream>
#include<vector>
using namespace std;
const int maxn=1010;
int heap[maxn];
vector<int> v;
int n,isMin=1,isMax=1;
//DFS 先序遍历 根-右-左 
void DFS(int index)
{
    if(index*2>n && index*2+1>n){
        if(index<=n){
            for(int i=0;i<v.size();i++){
                cout << v[i];
                if(i!=v.size()-1){
                    cout << " ";
                }else{
                    cout << "\n";
                }
            }
        }
    }else{
        v.push_back(heap[index*2+1]);
        DFS(index*2+1);
        v.pop_back();
        v.push_back(heap[index*2]);
        DFS(index*2);
        v.pop_back();
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> heap[i];
    }
    v.push_back(heap[1]);
    DFS(1);
    for(int i=2;i<=n;i++){
        if(heap[i/2]>heap[i]) isMin=0;
        if(heap[i/2]<heap[i]) isMax=0;
    }
    if(isMin==1){
        cout << "Min Heap";
    }else if(isMax==1){
        cout << "Max Heap";
    }else{
        cout << "Not Heap";
    }
    return 0;
}