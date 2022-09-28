#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//20'
struct node{
    int start,end;
    int diff;
};
bool cmp(node a,node b)
{
    if(a.end!=b.end) return a.end>b.end;
    else if(a.diff!=b.diff) return a.diff<b.diff;
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
        v[i].diff=v[i].end-v[i].start;
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=0;
    // for(int i=0;i<v.size();i++){
    //     cout << v[i].start << " " << v[i].end << "  " << v[i].diff << endl;
    // }
    for(int i=0,j=i+1;i<v.size();){
        if(v[j].end<=v[i].start){
            cnt++;
            i=j;
        }else{
            j++;
        }
    }
    cout << cnt;
    return 0;
}