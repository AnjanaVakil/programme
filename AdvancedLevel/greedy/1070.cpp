#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//16:23-16:53 25score
struct mooncake{
    double inventory;
    double price;
    double unit;
};
bool cmp(mooncake a,mooncake b)
{
    return a.unit>b.unit;
}
int main()
{
    int n,d;
    cin >> n >> d;
    vector<mooncake> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].inventory;
    }
    // for(int i=0;i<n;i++){
    //     cin >> v[i].price;
    // }
    // for(int i=0;i<n;i++){
    //     v[i].unit=v[i].price/v[i].inventory;
    // }
    //优化
    for(int i=0;i<n;i++){
        cin >> v[i].price;
        v[i].unit=v[i].price/v[i].inventory;
    }
    sort(v.begin(),v.end(),cmp);
    // for(int i=0;i<v.size();i++){
    //     cout << v[i].inventory << " " << v[i].unit << endl;
    // }
    double res;
    int i=0;
    while(i<v.size() && d>0){
        if(v[i].inventory<=d){
            d-=v[i].inventory;
            res+=v[i].price;
        }else{
            res+=v[i].unit*d;
            d=0;
        }
        i++;
    }
    printf("%.2f",res);
    return 0;
}