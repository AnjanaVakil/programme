#include<iostream>
using namespace std;
int main()
{
    int n,a,b;
    cin >> n;
    int hash[100000]={0};
    for(int i=0;i<n;i++){
        cin >> a >> b;
        hash[a]+=b;
    }
    //正整数 N，即参赛人数
    //学校的编号（从 1 开始连续编号）
    //所以遍历数组到N就可以，不用全部遍历
    int maxid=1,max=hash[1];
    for(int i=2;i<=n;i++){
        if(hash[i]>max){
            max=hash[i];
            maxid=i;
        }
    }
    cout << maxid << " " << max;
    return 0;
}