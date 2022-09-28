#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        //初始取值很重要
        int g2,g1=0,max=-1,min=m+1,temp,cnt=-2;
        cin >> g2;
        for(int j=0;j<n-1;j++){
            cin >> temp;
            if(temp<=m && temp>=0){
                if(temp>max) max=temp;
                if(temp<min) min=temp;
                g1+=temp;
                cnt++;
            }
        }
        int res=( (g2+(g1-max-min)*1.0/cnt)/2+0.5 );
        cout << res << endl;
    }
    return 0;
}