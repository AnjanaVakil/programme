#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string id,minid,maxid;
    int x,y,minvalue=10000,maxvalue=0;
    for(int i=0;i<n;i++){
        cin >> id >> x >> y;
        int t=x*x+y*y;
        if(t<=minvalue){
            minid=id;
            minvalue=t;
        }
        if(t>=maxvalue){
            maxid=id;
            maxvalue=t;
        }
    }
    cout << minid << " " << maxid;
    return 0;
}