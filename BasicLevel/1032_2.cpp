#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //正整数 N，即参赛人数
    //学校的编号（从 1 开始连续编号）
    int n,a,b;
    cin >> n;
    vector<int> v(n+1);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v[a]+=b;
    }
    int maxid=1,max=v[1];
    for(int i=2;i<=n;i++){
        if(v[i]>max){
            max=v[i];
            maxid=i;
        }
    }
    cout << maxid << " " << max;
    return 0;
}