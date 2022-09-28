#include<iostream>
#include<vector>
using namespace std;
//15:13-15:33 20min 17‘运行超时
int main()
{
    int n,m;
    cin >> n;
    vector<int> dis(n+1);
    for(int i=1;i<=n;i++){
        cin >> dis[i];
    }
    cin >> m;
    int a,b;
    for(int j=0;j<m;j++){
        cin >> a >> b;
        if(a>b){
            swap(a,b);
            // int temp=a;
            // a=b;
            // b=temp;
        }
        int t1=0;
        for(int i=a;i<b;i++){
            t1+=dis[i];
        }
        int t2=0;
        for(int i=1;i<a;i++){
            t2+=dis[i];
        }
        for(int i=b;i<=n;i++){
            t2+=dis[i];
        }
        printf("%d\n",t1<t2?t1:t2);
    }
    return 0;
}