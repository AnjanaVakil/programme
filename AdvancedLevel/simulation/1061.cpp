#include<iostream>
#include<cctype>
using namespace std;
//15:42-16:05 14'
//相同的字符必须得在同一位置处，用find函数是错误的，直接比较
//认真读题！！！
string days[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    //9 A B C D E F G
    // cout << 'D'-'A' << endl;//3
    int i,j;
    for(i=0;i<a.length() && i<b.length();i++){
        //不能用isupper，要用A-G限定
        // if(isupper(a[i]) && a[i]==b[i]){
        //     cout << days[a[i]-'A'] << " ";
        //     break;
        // }
        if(a[i]==b[i] && a[i]>='A' && a[i]<='G'){
            cout << days[a[i]-'A'] << " ";
            break;
        }
        // if(a[i]>='A' && a[i]<='G' && a[i]==b[i]){
        //     cout << days[a[i]-'A'] << " ";
        //     break;
        // }
    }
    for(j=i+1;j<a.length() && j<b.length();j++){
        if(a[j]==b[j] && isdigit(a[j])){
            // printf("%02d:",a[j]);错误 
            //%d输出的是数字，要将 字符类型的数字 转换为 数字型
            printf("%02d",a[j]-'0');
            break;
        }
        //不能用isupper，要用A-N限定
        if(a[j]==b[j] && a[j]>='A' && a[j]<='N'){
            printf("%02d:",a[j]-'A'+10);
            break;
        }
        // if(isdigit(a[j]) && a[j]==b[j]){
        //     // printf("%02d:",a[j]);错误 
        //     //%d输出的是数字，要将 字符类型的数字 转换为 数字型
        //     printf("%02d",a[j]-'0');
        //     break;
        // }
        // //不能用isupper，要用A-N限定
        // if(a[j]>='A' && a[j]<='N' && a[j]==b[j]){
        //     printf("%02d:",a[j]-'A'+10);
        //     break;
        // }
    }
    for(int k=0;k<c.length() && k<d.length();k++){
        if(c[k]==d[k] && isalpha(c[k])){
            printf("%02d",k);
            break;
        }
    }
    return 0;
}