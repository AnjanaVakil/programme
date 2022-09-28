#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int nc,np;
    cin >> nc;
    vector<int> coupon(nc);
    for(int i=0;i<nc;i++){
        cin >> coupon[i];
    }
    cin >> np;
    vector<int> product(np);
    for(int i=0;i<np;i++){
        cin >> product[i];
    }
    //-1 1 2 4
    //-3 -2 6 7 
    //3 -2 12 28
    //28 12 
    sort(coupon.begin(),coupon.end());
    sort(product.begin(),product.end());
    int res=0;
    int m=nc-1,n=np-1;
    while(m>=0 && n>=0 && coupon[m]>0 && product[n]>0){
        res+=coupon[m]*product[n];
        m--;
        n--;
    }
    m=0,n=0;
    while(m<nc && n<np && coupon[m]<0 && product[n]<0){
        res+=coupon[m]*product[n];
        m++;
        n++;
    }
    cout << res;
    return 0;
}