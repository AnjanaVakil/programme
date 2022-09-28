#include<iostream>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int sum=0;
    for(int i=0;i<s.length();i++){
        //s[i]>='A' && s[i]<='z'是错误的，要对几个特殊字符的ASCII熟记于心啊
        //A 65 Z 90 a 97 z 122 
        //Z 和 a 之间隔了6个字符
        //所以这样判断是否是字母是错误的
        if(isalpha(s[i])){
            int num=(isupper(s[i])? s[i]-'A'+1:s[i]-'a'+1);
            sum+=num;
        }
    }
    int cnt0=0,cnt1=0;
    while(sum!=0){
        if(sum%2==0) cnt0++;
        else cnt1++;
        sum/=2;
    }
    cout << cnt0 << " " << cnt1;
    return 0;
}