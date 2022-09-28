#include<iostream>
#include<vector>
#include<map>
using namespace std;
//30'
map<int,bool> mp;
int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for(int i=0;i<n;i++){
        scanf("%d", &pre[i]);
        mp[pre[i]]=true;
    }
    int u,v,root;
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        for(int j=0;j<n;j++){
            root=pre[j];
            if((root>u && root<v) || (root<u && root>v) || (root==u) || (root==v)) break;
        }
        if(mp[u]==false && mp[v]==false){
            printf("ERROR: %d and %d are not found.\n",u,v);
        }else if(mp[u]==false || mp[v]==false){
            printf("ERROR: %d is not found.\n",mp[u]==false?u:v);
        }else if(root==u || root==v){
            printf("%d is an ancestor of %d.\n",root,root==u?v:u);
        }else{
            printf("LCA of %d and %d is %d.\n",u,v,root);
        }
    }
    return 0;
}