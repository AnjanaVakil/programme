#include<iostream>
#include<climits>
using namespace std;
int main()
{
    //将时间都转换为总秒数，最早和最迟的时间保存在变量minn和maxn中
    int m,minn=INT_MAX,maxn=INT_MIN;
    scanf("%d",&m);
    string unlocked,locked;
    for(int i=0;i<m;i++){
        string t;
        cin >> t;
        int h1,m1,s1,h2,m2,s2;
        scanf("%d:%d:%d %d:%d:%d",&h1, &m1, &s1, &h2, &m2, &s2);
        int tempIn=h1*3600+m1*60+s1;
        int tempOut=h2*3600+m2*60+s2;
        if(tempIn<minn){
            minn=tempIn;
            unlocked=t;
        }
        if(tempOut>maxn){
            maxn=tempOut;
            locked=t;
        }
    }
    cout << unlocked << " " << locked;
    return 0;
}