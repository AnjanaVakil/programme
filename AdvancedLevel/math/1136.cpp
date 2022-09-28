#include<iostream>
#include<algorithm>
using namespace std;
//16'
int main()
{
    //gives a positive integer no more than 1000 digits.
    //大整数加法
    string s;
    cin >> s;
    int n=10;
    int flag=0;
    while(n--){
        int a=stoi(s);
        reverse(s.begin(),s.end());
        int b=stoi(s);
        if(a==b){
            flag=1;
            printf("%d is a palindromic number.",a);
            return 0;
        }
        int c=a+b;
        printf("%d + %d = %d\n",a,b,c);
        s=to_string(c);
    }
    if(flag==0){
        printf("Not found in 10 iterations.");
    }
    return 0;
}