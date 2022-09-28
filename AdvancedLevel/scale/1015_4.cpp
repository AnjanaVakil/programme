#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//首先判断N,若N不是素数直接输出No
//否则将其转换为D进制，然后逆序，再将逆序后的D进制数转换为十进制数q，判断q是否为素数即可。
//n由 10进制转d进制 1<d<=10
vector<int> TenToD(int n,int d)
{
    vector<int> resD;
    do{
        resD.push_back(n%d);
        n/=d;
    }while(n!=0);
    return resD;
}
int revToTen(vector<int> resD,int d)
{
    // int result=0;
    // for(int i=0;i<resD.size();i++){
    //     result=result*d+resD[i];
    // }
    // return result;
    int p=1,result=0;
    for(int i=resD.size()-1;i>=0;i--){
        result+=p*resD[i];
        p*=d;
    }
    return result;
}
//判断prime
bool is_prime(int n)
{
    if(n<=1) return false;
    // int num=floor(sqrt(n)+0.5);
    //另一种写法
    int num=int(sqrt(n*1.0));
    for(int i=2;i<=num;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n,d;
    // freopen("input.txt","r",stdin); 
    while(cin >> n >> d){
        if(n<0) break;
        vector<int> resD=TenToD(n,d);
        // for(int i=0;i<resD.size();i++) cout << resD[i];
        // cout << endl;
        int result=revToTen(resD,d);
        // cout << result << endl;
        if(is_prime(n) && is_prime(result)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}