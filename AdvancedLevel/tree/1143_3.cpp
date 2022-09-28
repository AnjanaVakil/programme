#include<iostream>
#include<vector>
#include<map>
using namespace std;
//30'
vector<int> pre;
map<int,bool> mp;
void LCA(int a,int b)
{
    for(int i=0;i<pre.size();i++){
        if((a<pre[i] && b>pre[i]) || (a>pre[i] && b<pre[i])){
            printf("LCA of %d and %d is %d.\n",a,b,pre[i]);
            return;
        }else if(a==pre[i] || b==pre[i]){
            printf("%d is an ancestor of %d.\n",pre[i],a==pre[i]?b:a);
            return;
        }
    }
}
int main()
{
    int m,n;
    cin >> m >> n;
    pre.resize(n);
    for(int i=0;i<n;i++){
        cin >> pre[i];
        mp[pre[i]]=true;
    }
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        if(mp[a] && mp[b]){
            LCA(a,b);
        }else if(mp[a]==false && mp[b]==false){
            printf("ERROR: %d and %d are not found.\n",a,b);
        }else if(mp[a]==false || mp[b]==false){
            printf("ERROR: %d is not found.\n",mp[a]==false?a:b);
        }
    }
    return 0;
}