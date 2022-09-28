#include<iostream>
#include<vector>
using namespace std;
//15:28-16:10 又是段错误
//自己写的这是什么垃圾代码
int main()
{
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int n;
        cin >> n;
        int flag=0;
        int diagonal[1000][1000];
        vector<int> q;
        for(int j=1;j<=n;j++){
            cin >> q[j];
            diagonal[q[j]][j]=1;
        }
        for(int j=1;j<=n;j++){
            //row
            for(int l=1;l<j;l++){
                if(diagonal[q[j]][l]==1){
                    flag=1;
                    break;
                }
            }
            //diagonal
            int t1=q[j],t2=j;
            while(t1>=1 && t2<=n){
                if(diagonal[t1--][t2++]==1){
                    flag=1;
                    break;
                }
            }
            int t3=q[j],t4=j;
            while(t3<=n && t4>=1){
                if(diagonal[t3++][t4--]==1){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}