#include<iostream>
#include<vector>
using namespace std;
//30'
vector<int> level;
int m,n;
bool isMaxHeap(vector<int> level)
{
    if(n%2==0){
        if(level[n/2]<level[n]) return false;
        for(int i=n/2-1;i>=1;i--){
            if(level[i]<level[2*i] || level[i]<level[2*i+1]){
                return false;
            }
        }
    }else{
        for(int i=n/2;i>=1;i--){
            if(level[i]<level[2*i] || level[i]<level[2*i+1]){
                return false;
            }
        }
    }
    return true;
}
bool isMinHeap(vector<int> level)
{
    if(n%2==0){
        if(level[n/2]>level[n]) return false;
        for(int i=n/2-1;i>=1;i--){
            if(level[i]>level[2*i] || level[i]>level[2*i+1]){
                return false;
            }
        }
    }else{
        for(int i=n/2;i>=1;i--){
            if(level[i]>level[2*i] || level[i]>level[2*i+1]){
                return false;
            }
        }
    }
    return true;
}
vector<int> res;
void postorder(int index)
{
    if(index>n) return;
    postorder(index*2);
    postorder(index*2+1);
    res.push_back(level[index]);
}
int main()
{
    cin >> m >> n;
    for(int i=0;i<m;i++){
        //下标从1开始的话要resize(n+1),否则答案有错误
        level.resize(n+1);
        for(int j=1;j<=n;j++){
            cin >> level[j];
        }
        if(isMaxHeap(level)){
            printf("Max Heap\n");
        }else if(isMinHeap(level)){
            printf("Min Heap\n");
        }else{
            printf("Not Heap\n");
        }
        postorder(1);
        for(int i=0;i<res.size();i++){
            if(i!=0) printf(" ");
            printf("%d",res[i]);
        }
        printf("\n");
        res.clear();
        //每回res都要清空，否则会加上之前的结果输出，多练习，不要犯这种愚蠢的错误
    }
    return 0;
}