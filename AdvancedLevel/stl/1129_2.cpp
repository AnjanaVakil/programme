#include<iostream>
#include<set>
using namespace std;
int book[500010];
struct node{
    int num,feq;
    node(int a,int b):num(a),feq(b){}
    bool operator < (const node &a) const{
        return (feq!=a.feq)?feq>a.feq:num<a.num;
    }
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
    set<node> s;
    int query;
    for(int i=0;i<n;i++){
        cin >> query;
        if(i!=0){
            printf("%d:",query);
            int tempCnt=0;
            for(auto it=s.begin();it!=s.end() && tempCnt<k;it++){
                printf(" %d",it->num);
                tempCnt++;
            }
            printf("\n");
        }
        auto it=s.find(node(query,book[query]));
        if(it!=s.end()) s.erase(it);
        book[query]++;
        s.insert(node(query,book[query]));
    }
    return 0;
}