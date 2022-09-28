#include<iostream>
#include<map>
#include<vector>
using namespace std;
//14:33-15:10 基本思路对了但是有bug
//14:33-15:21 25score
int main()
{
    int n,m;
    cin >> n >> m;
    int a,b;
    map<int,vector<int> > imcompatiable;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        imcompatiable[a].push_back(b);
        imcompatiable[b].push_back(a);
    }
    // vector<int> isExist(100000,0);
    //这个导致错误答案，应该写到循环里面
    //每次判断都需要初始化为0，否则会保留上次的isExist
    for(int i=0;i<m;i++){
        vector<int> isExist(100000,0);
        int k;
        int j;
        cin >> k;
        vector<int> goods(k);
        for(j=0;j<k;j++){
            cin >> goods[j];
            isExist[goods[j]]=1;
        }
        int flag=0;
        for(j=0;j<k;j++){
            for(int l=0;l<imcompatiable[goods[j]].size();l++){
                if(isExist[ imcompatiable[goods[j]][l] ]==1){
                    cout << "No\n";
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==0){
            cout << "Yes\n";
        }
    }
    return 0;
}