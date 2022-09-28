#include<iostream>
using namespace std;
//33-
int n;
string deal(string s,int &k)
{
    int i=0;//下标
    while(s.length()>0 && s[0]=='0'){
        s.erase(s.begin());
    }
    if(s[0]=='.'){
        //0.a1a2a3这种类型
        s.erase(s.begin());//去掉小数点.
        while(s.length()>0 && s[0]=='0'){
            k--;//指数--
            s.erase(s.begin());
        }
    }else{
        //b1b2b3.a1a2a3这种类型
        while(k<s.length() && s[k]!='.'){
            i++;
            k++;
        }
        if(k<s.length()){
            s.erase(s.begin()+k); //删除小数点
        }
    }
    if(s.length()==0){
        k=0;
    }
    string res;
    int num=0;
    i=0;
    while(num<n){
        if(i<s.length()) res+=s[i++];
        else res+='0';
        num++;
    }
    return res;
}
int main()
{
    string a,b;
    cin >> n >> a >> b;
    int k1=0,k2=0;//指数
    string d1=deal(a,k1);
    string d2=deal(b,k2);
    if(d1==d2 && k1==k2){
        cout << "YES 0." << d1 << "*10^" << k1;
    }else{
        cout << "NO 0." << d1 << "*10^" << k1 << " 0." << d2 << "*10^" << k2;
    }
    return 0;
}