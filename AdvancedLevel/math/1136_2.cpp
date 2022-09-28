#include<iostream>
#include<algorithm>
using namespace std;
//20'
string add(string a,string b)
{
    string sum;
    int carry=0;
    for(int i=0;i<a.length();i++){
        int temp=(a[i]-'0'+b[i]-'0')+carry;
        sum+=char(temp%10+'0');
        carry=temp/10;
    }
    if(carry!=0){
        sum+=char(carry+'0');
    }
    reverse(sum.begin(),sum.end());
    return sum;
}
int main()
{
    //gives a positive integer no more than 1000 digits.
    //大整数加法
    string s;
    cin >> s;
    int cnt=0;
    while(cnt<10){
        string a=s;
        reverse(s.begin(),s.end());
        string b=s;
        if(a==b){
            printf("%s is a palindromic number.",a.c_str());
            break;
        }else{
            s=add(a,b);
            printf("%s + %s = %s\n",a.c_str(),b.c_str(),s.c_str());
            cnt++;
        }
    }
    if(cnt==10){
        printf("Not found in 10 iterations.");
    }
    return 0;
}