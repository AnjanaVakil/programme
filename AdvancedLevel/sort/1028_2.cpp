#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
//26-42 25'
//10^6 2^20
struct node{
    int id;
    char name[10];
    int grade;
};
bool cmp1(node a,node b)
{
    return a.id<b.id;
}
bool cmp2(node a,node b)
{
    return strcmp(a.name,b.name)!=0?strcmp(a.name,b.name)<0:a.id<b.id;
}
bool cmp3(node a, node b)
{
    return a.grade!=b.grade?a.grade<b.grade:a.id<b.id;
}
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    vector<node> v(n);
    for(int i=0;i<n;i++){
        scanf("%d%s%d",&v[i].id,v[i].name,&v[i].grade);
    }
    if(c==1){
        sort(v.begin(),v.end(),cmp1);
    }else if(c==2){
        sort(v.begin(),v.end(),cmp2);
    }else{
        sort(v.begin(),v.end(),cmp3);
    }
    for(int i=0;i<v.size();i++){
        printf("%06d %s %d\n",v[i].id,v[i].name,v[i].grade);
    }
    return 0;
}