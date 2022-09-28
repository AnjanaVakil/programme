#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#define maxn 100005
int ans[maxn];
int single[maxn];
using namespace std;
//每人对应一个 ID 号，为 5 位数字（从 00000 到 99999）
//所以不能初始化为0，应该初始化为-1
bool is_single(int t,int m)
{
    if(ans[t]==-1) return true;
    for(int i=0;i<m;i++){
        if(ans[t]==single[i]){
            return false;
        }
    }
    return true;
}
int main()
{
    int n,m,a,b;
    cin >> n;
    memset(ans,-1,sizeof(ans)); //头文件是string.h
    vector<int> res;
    while(n--){
        cin >> a >> b;
        ans[a]=b;
        ans[b]=a;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> single[i];
    }
    for(int i=0;i<m;i++){
        if(is_single(single[i],m)){
            res.push_back(single[i]);
        }
    }
    sort(res.begin(),res.end());
    printf("%lu\n",res.size());
    int first=1;
    for(int i=0;i<res.size();i++){
        if(!first){
            printf(" ");
        }
        printf("%05d",res[i]);
        first=0;
    }
    return 0;
}