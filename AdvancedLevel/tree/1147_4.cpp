#include<iostream>
#include<vector>
using namespace std;
//30'
vector<int> level;
int m,n;
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
        int maxHeap=1,minHeap=1;
        level.resize(n+1);
        for(int j=1;j<=n;j++){
            cin >> level[j];
        }
        //这边只用遍历一次即可
        for(int j=2;j<=n;j++){
            if(level[j]<level[j/2]) minHeap=0;
            if(level[j]>level[j/2]) maxHeap=0;
        }
        if(maxHeap){
            printf("Max Heap\n");
        }else if(minHeap){
            printf("Min Heap\n");
        }else{
            printf("Not Heap\n");
        }
        postorder(1);
    }
    return 0;
}