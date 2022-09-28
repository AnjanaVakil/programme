#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//25score 
int main()
{
    int n,m;
    scanf("%d",&n);
    int a,b;
    vector<int> couple(100000,-1);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        couple[a]=b;
        couple[b]=a;
    }
    scanf("%d",&m);
    vector<int> guest(m);
    vector<int> res;
    for(int i=0;i<m;i++){
        scanf("%d",&guest[i]);
    }
    for(int i=0;i<m;i++){
        //编号有可能是000000
        if(couple[guest[i]]==-1){
            res.push_back(guest[i]);
        }else{
            //没找到
            if( find(guest.begin(),guest.end(),couple[guest[i]])==guest.end() ){
                res.push_back(guest[i]);
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