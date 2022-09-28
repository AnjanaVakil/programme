#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin >> n;
    //vector初始化为n+1时，要放在cin >> n后面，否则段错误
    vector<int> dis(n+1);
    int sum=0,temp;
    for(int i=1;i<=n;i++){
        cin >> temp;
        sum+=temp;
        dis[i]=sum;
        //1 3 7 21 30
    }
    cin >> m;
    int a,b;
    for(int j=0;j<m;j++){
        cin >> a >> b;
        if(a>b){
            swap(a,b);
        }
        int temp=dis[b-1]-dis[a-1];
        printf("%d\n",min(temp,sum-temp));
    }
    return 0;
}