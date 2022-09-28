#include<iostream>
using namespace std;
//13:38-14:28 50min 也没有全部写出来，这思维也太差了吧
string dic1[]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string dic2[]={"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
string decimalToBase(int n)
{
    //自己写的这个只有16score
    // string b=dic1[n%13];
    // string a=dic2[n/13];
    // if((n/13) && (n%13)) a+=" "; 
    // return a+b;
    string a,b;
    if(n/13) a=dic2[n/13];
    if((n/13) && (n%13)) a+=" "; 
    if(n%13 || n==0) b=dic1[n%13];
    return a+b;
}
int baseToDecimal(string s)
{
    //s.substr(pos,n)
    string s1=s.substr(0,3),s2;
    if(s.length()>4){
        s2=s.substr(4,3);
    }
    // cout << s1 << " " << s2 << endl;
    int t1=0,t2=0;
    for(int i=1;i<13;i++){
        if(s1==dic1[i] || s2==dic1[i]) t2=i;
        if(s1==dic2[i]) t1=i;
    }
    return t1*13+t2;
}
int main()
{
    int n;
    cin >> n;
    //169 
    //115 
    //12*13=156 156+13=169 156+12=168
    getchar();
    for(int i=0;i<n;i++){
        //getchar的错误查找了半天，不应该写在循环里面，否则后面就会出错
        // getchar(); 写在循环是错误的
        string num;
        getline(cin,num);
        if(isdigit(num[0])){
            cout << decimalToBase(stoi(num));
        }else{
            cout << baseToDecimal(num);
        }
        cout << endl;
    }
    return 0;
}