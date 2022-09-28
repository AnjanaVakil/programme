#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//15:55-25 19'
//运行超时，说明不能只是单纯的简单模拟
struct node{
    int a,b;
    int sum;
};
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> d(n+1);
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
    int min=INT_MAX;
    int i=1;
    vector<node> v;
    int equal=0;
    while(i<=n){
        int temp=d[i];
        if(temp==m){
            equal=1;
            node t;
            t.a=i;
            t.b=i;
            t.sum=temp;
            v.push_back(t);
        }
        for(int j=i+1;j<=n;j++){
            if(temp<m){
                temp+=d[j];
                if(temp==m){
                    equal=1;
                    node t;
                    t.a=i;
                    t.b=j;
                    t.sum=temp;
                    v.push_back(t);
                    break;
                }
                if(equal==0 && temp>m){
                    if(temp<=min){
                        min=temp;
                        node t;
                        t.a=i;
                        t.b=j;
                        t.sum=temp;
                        v.push_back(t);
                        break;
                    }
                }
            }else{
                break;
            }
        }
        i++;
    }
    if(equal==1){
        for(int i=0;i<v.size();i++){
            printf("%d-%d\n",v[i].a,v[i].b);
        }
    }else{
        for(int i=0;i<v.size();i++){
            if(v[i].sum==min){
                printf("%d-%d\n",v[i].a,v[i].b);
            }
        }
    }
    return 0;
}