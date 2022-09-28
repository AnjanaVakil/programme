#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int start,end;
};
bool cmp(node a,node b)
{
    if(a.end!=b.end) return a.end<b.end;
    else return a.start>b.start;
}
int main()
{
    int n;
    cin >> n;
    vector<node> v(n);
    int h,m,s,a,b,c;
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d %d:%d:%d",&h,&m,&s,&a,&b,&c);
        v[i].start=h*3600+m*60+s;
        v[i].end=a*3600+b*60+c;
    }
    sort(v.begin(),v.end(),cmp);
    // for(int i=0;i<v.size();i++){
    //     cout << v[i].start << " " << v[i].end << endl;
    // }
    int cnt=1;
    int last=v[0].end;
    for(int i=1;i<v.size();i++){
        if(v[i].start>=last){
            cnt++;
            last=v[i].end;
        }
    }
    cout << cnt;
    return 0;
}