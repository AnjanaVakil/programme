// #include<iostream>
// using namespace std;
// int main()
// {
//     //1 2 3 3 4 5 5 6 7 9
//     int n;
//     cin >> n;
//     //段错误,使用了3个数组,真的很笨
//     int a[100001],b[100001],c[200001];
//     for(int i=0;i<n;i++){
//         cin >> a[i];
//     }
//     for(int i=0;i<n;i++){
//         cin >> b[i];
//     }
//     int i=0,j=0,k=0;
//     while(i<n || j<n){
//         if(a[i]<=b[j]){
//             c[k++]=a[i++];
//         }else{
//             c[k++]=b[j++];
//         }
//     }
//     cout << c[(2*n-1)/2];
//     return 0;
// }

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,i;
    cin >> n;
    int a[200001];
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(;i<2*n;i++){
        cin >> a[i];
    }
    sort(a,a+2*n);
    cout << a[(2*n-1)/2];
    return 0;
}

