#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//23score 
int main()
{
    int n,m;
    scanf("%d",&n);
    int a,b;
    map<int,int> mapp;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        mapp[a]=b;
        mapp[b]=a;
    }
    scanf("%d",&m);
    vector<int> v(m);
    vector<int> res;
    for(int i=0;i<m;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0;i<m;i++){
        //编号有可能是000000
        //不知道map怎么初始化，只能改成vector<int>
        if(mapp[v[i]]==0){
            res.push_back(v[i]);
        }else{
            //没找到
            if( find(v.begin(),v.end(),mapp[v[i]])==v.end() ){
                res.push_back(v[i]);
            }
        }
    }
    printf("%d\n",res.size());
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        if(i!=0) printf(" ");
        printf("%05d",res[i]);
    }
    return 0;
}