#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int book[50010];
struct node{
    int num,feq;
};
bool cmp(node a,node b)
{
    if(a.feq!=b.feq) return a.feq>b.feq;
    else return a.num<b.num;

}
int main()
{
    int n,k;
    cin >> n >> k;
    vector<node> res;
    map<int,node> mp;
    int query;
    for(int i=0;i<n;i++){
        int query;
        cin >> query;
        if(i!=0){
            printf("%d:",query);
            for(auto it=mp.begin();it!=mp.end();it++){
                res.push_back(it->second);
            }
            sort(res.begin(),res.end(),cmp);
            for(int j=0;j<k;j++){
                if(res[j].feq!=0) printf(" %d",res[j].num);
            }
            printf("\n");
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->first==query){
                mp.erase(it);
            }
        }
        book[query]++;
        node temp;
        temp.num=query;
        temp.feq=book[query]++;
        mp[query]=temp;
    }
    return 0;
}