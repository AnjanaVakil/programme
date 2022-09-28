#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//15:10-27 22score
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
    //部分正确 22score
    // int m=coupon.size()-1;
    // int n=product.size()-1;
    // while(m>=0 && n>=0){
    //     if(coupon[m]*product[n]>0){
    //         res+=coupon[m]*product[n];
    //         // cout << res << " ";
    //     }
    //     m--;
    //     n--;
    // }
    //部分正确 22score
    int m=0,n=0;
    while(m<nc && n<np){
        if(coupon[m]*product[n]>0){
            res+=coupon[m]*product[n];
        }
        m++;
        n++;
    }
    cout << res;
    return 0;
}