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
void postorder(int index)
{
    if(index>n) return;
    postorder(index*2);
    postorder(index*2+1);
    //利用index来控制最后输出 空格 还是 换行
    printf("%d%s",level[index],index==1?"\n":" ");
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
    }
    return 0;
}