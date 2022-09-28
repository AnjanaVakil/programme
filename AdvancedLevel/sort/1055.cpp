#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
//比较排序的这类题中，结构体中最好还是用char数组,不要用string，容易出错
using namespace std;
//18'
struct node{
    char name[10];
    int age,worth;
};
bool cmp(node a,node b)
{
    if(a.worth!=b.worth) return a.worth>b.worth;
    else if(a.age!=b.age) return a.age<b.age;
    else return strcmp(a.name,b.name)<0;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<node> v(n);
    for(int i=0;i<n;i++){
        scanf("%s%d%d",v[i].name,&v[i].age,&v[i].worth);
    }
    int m,a,b;
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<=k;i++){
        cin >> m >> a >> b;
        if(i!=1) printf("\n");
        printf("Case #%d:",i);
        int cnt=0;
        for(int j=0;j<v.size() && cnt<m;j++){
            if(v[j].age>=a && v[j].age<=b){
                printf("\n%s %d %d",v[j].name,v[j].age,v[j].worth);
                cnt++;
            }
        }
        if(cnt==0){
            printf("\nNone");
        }
    }
    return 0;
}