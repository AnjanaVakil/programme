#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
//26-42 25'
struct node{
    char id[10],name[10];
    int grade;
};
bool cmp1(node a,node b)
{
    return strcmp(a.id,b.id)<0;
}
bool cmp2(node a,node b)
{
    return strcmp(a.name,b.name)!=0?strcmp(a.name,b.name)<0:strcmp(a.id,b.id)<0;
}
bool cmp3(node a, node b)
{
    return a.grade!=b.grade?a.grade<b.grade:strcmp(a.id,b.id)<0;
}
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    vector<node> v(n);
    for(int i=0;i<n;i++){
        scanf("%s%s%d",v[i].id,v[i].name,&v[i].grade);
    }
    if(c==1){
        sort(v.begin(),v.end(),cmp1);
    }else if(c==2){
        sort(v.begin(),v.end(),cmp2);
    }else{
        sort(v.begin(),v.end(),cmp3);
    }
    for(int i=0;i<v.size();i++){
        printf("%s %s %d\n",v[i].id,v[i].name,v[i].grade);
    }
    return 0;
}