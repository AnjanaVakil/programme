#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
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
    //n 10^5 m 100 相差太悬殊
    int n,k;
    // cin >> n >> k;
    scanf("%d%d",&n,&k);
    vector<node> v(n);
    for(int i=0;i<n;i++){
        scanf("%s%d%d",v[i].name,&v[i].age,&v[i].worth);
    }
    int m,a,b;
    sort(v.begin(),v.end(),cmp);
    vector<node> vt;
    vector<int> book(205,0);
    for(int i=0;i<n;i++){
        if(book[v[i].age]<100){
            vt.push_back(v[i]);
            book[v[i].age]++;
        }
    }
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&m,&a,&b);
        printf("Case #%d:\n",i);
        vector<node> t;
        for(int j=0;j<v.size();j++){
            if(vt[j].age>=a && vt[j].age<=b){
                t.push_back(vt[j]);
            }
        }
        int flag=0;
        for(int j=0;j<t.size() && j<m;j++){
            printf("%s %d %d\n",t[j].name,t[j].age,t[j].worth);
            flag=1;
        }
        if(flag==0){
            printf("None\n");
        }
    }
    return 0;
}