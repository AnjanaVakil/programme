#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    //两个不超过 1000 的正整数 A 和 B
    int a,b;
    cin >> a >> b;
    string s=to_string(a*b);
    reverse(s.begin(),s.end());
    //乘积结果之前的全0要去掉
    cout << stoi(s);
    return 0;
}
// #include<iostream>
// using namespace std;
// int main()
// {
//     int a,b;
//     cin >> a >> b;
//     int res=a*b;
//     while(res%10==0){
//         res/=10;
//     }
//     while(res){
//         cout << res%10;
//         res/=10;
//     }
//     return 0;
// }