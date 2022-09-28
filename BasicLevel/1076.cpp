// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     string ans;
//     for(int i=0;i<n+1;i++){
//         string s;
//         getline(cin,s);
//         int a=s.find('T');
//         int b=a-2;
//         switch(s[b]){
//             case 'A':ans+="1";break;
//             case 'B':ans+="2";break;
//             case 'C':ans+="3";break;
//             case 'D':ans+="4";break;
//         }
//     }
//     for(int i=0;i<ans.length();i++){
//         cout << ans[i];
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    for(int i=0;i<n+1;i++){
        getline(cin,s);
        int a=s.find('T');
        int b=a-2;
        switch(s[b]){
            case 'A':printf("1");break;
            case 'B':printf("2");break;
            case 'C':printf("3");break;
            case 'D':printf("4");break;
        }
    }
    return 0;
}