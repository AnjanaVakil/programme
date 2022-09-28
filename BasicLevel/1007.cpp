#include<iostream>
#include<math.h>
using namespace std;
// 答案正确
// bool isPrime(int n)
// {
//     for(int i=2;i<=sqrt(n);i++){
//         if(n%i==0) return false;
//     }
//     return true;
// }
// int main()
// {
//     int n,cnt=0;
//     cin >> n;
//     for(int i=3;i<=n-2;i++){
//         if(isPrime(i) && isPrime(i+2)){
//             cnt++;
//         }
//     }
//     cout << cnt;
// }
bool isPrime(int n)
{
    //超时运行错误 i<=n/2
    //答案正确 i=sqrt(n)
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n,cnt=0;
    cin >> n;
    for(int i=3;i<=n-2;i++){
        if(isPrime(i) && isPrime(i+2)){
            cnt++;
        }
    }
    cout << cnt;
}