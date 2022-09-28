#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int tea,res=0,v[101];
        int max=-1,maxid=-1,min=m+1,minid=-1;
        cin >> tea;
        for(int j=0;j<n-1;j++){
            cin >> v[j];
            if(v[j]<=m && v[j]>=0){
                if(v[j]>max){
                    max=v[j];
                    maxid=j;
                }
                if(v[j]<min){
                    min=v[j];
                    minid=j;
                }
            }
        }
        int cnt=0;
        for(int j=0;j<n-1;j++){
            if(v[j]<=m && v[j]>=0 && j!=maxid && j!=minid){
                res+=v[j];
                cnt++;
            }
        }
        cout << int( ( (tea+res*1.0/cnt)/2 +0.5) ) << endl;
    }
    return 0;
}