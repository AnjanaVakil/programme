#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=99999999;
//15:12-15:41 30min也太多细节了 写了一半实在写不下去了
//不要照着别人的代码敲代码，这样完全没有理解啊！还浪费了时间
//今天写不出来可以改天再写，一定是要自己思考过的
struct station{
    double unit;
    double dis;
};
// bool cmp(station a,station b)
// {
//     return (a.unit!=b.unit)?a.unit<b.unit:a.dis<b.dis;
// }
bool cmp(station a,station b)
{
    return (a.dis!=b.dis)?a.dis<b.dis:a.unit<b.unit;
}
int main()
{
    int max,d,avg,n;
    cin >> max >> d >> avg >> n;
    vector<station> sta(n);
    for(int i=0;i<n;i++){
        cin >> sta[i].unit >> sta[i].dis;
    }
    sort(sta.begin(),sta.end(),cmp);
    // for(int i=0;i<n;i++){
    //     cout << sta[i].unit << " " << sta[i].dis << endl;
    // }
    double nowdis=0.0,maxdis=0.0;
    double nowprice=0.0,totalprice=0.0;
    double leftdis=0.0;
    if(sta[0].dis!=0){
        cout << "The maximum travel distance = 0.00"; 
        return 0;
    }else {
        nowprice=sta[0].unit;
    }
    while(nowdis<d){
        maxdis=nowdis+max*avg;
        double minPriceDis=0,minPrice=inf;
        int flag=0;
        for(int i=1;i<=n && sta[i].dis<=maxdis;i++){
            if(sta[i].dis<=nowdis) continue;
            if(sta[i].unit<nowprice){
                totalprice+=(sta[i].dis-nowdis-leftdis)*nowprice/avg;
                leftdis=0.0;
                nowprice=sta[i].unit;
                nowdis=sta[i].dis;
                flag=1;
                break;
            }
            if(sta[i].unit<minPrice){
                minPrice=sta[i].unit;
                minPriceDis=sta[i].dis;
            }
        }
        if(flag==0 && minPrice!=inf){
            totalprice+=(nowprice*(max-leftdis/avg));
            leftdis=max*avg-(minPriceDis-nowdis);
            nowprice=minPrice;
            nowdis=minPriceDis;
        }
        if(flag==0 && minPrice==inf){
            nowdis+=max*avg;
            printf("The maximum travel distance == %.2f",nowdis);
            return 0;
        }
    }
    printf("%.2f",totalprice);
    return 0;
}