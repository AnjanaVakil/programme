#include<iostream>
#include<string>
using namespace std;
//自己并未成功写出来
int gcd(int x,int y)
{
    while(x!=y){
        if(x>y){
            x-=y;
        }else{
            y-=x;
        }
    }
    return x;
}
int main()
{
    int a,b,c,d,num;
    string s1,s2;
    cin >> s1 >> s2;
    int t=s1.find('/');
    a=stoi(s1.substr(0,t));
    cout << a << endl;
    b=stoi(s1.substr(t+1,s1.length()-1));
    cout << b << endl;
    t=s2.find('/');
    c=stoi(s2.substr(0,t));
    cout << c << endl;
    d=stoi(s2.substr(t+1,s2.length()-1));
    cout << d << endl;

    if(a<0){
        cout << "(";
    }
    num=gcd(a,b);
    if(a/b!=0){
        cout << a/b ;
        if(a%b!=0){
            cout << " " << a%b/num << "/" << b/num;
        }
    }else{
        if(a==0) cout << 0;
        else{
            cout << a%b/num << "/" << b/num;
        }
    }
    if(a<0){
        cout << "(";
    }
    cout << " + ";
    if(c<0){
        cout << "(";
    }
    num=gcd(c,d);
    if(c/d!=0){
        cout << c/d;
        if(c%d!=0){
            cout <<  " " << c%d/num << "/" << d/num;
        }
    }else{
        if(c==0) cout << 0;
        else{
            cout << c%d/num << "/" << d/num;
        }
    }
    if(c<0){
        cout << ")";
    }
    cout << " = ";
    int m=a*d+c*b;
    int n=b*d; 
    if(m<0){
        cout << "(";
    }
    num=gcd(m,n);
    if(m/n!=0){
        cout << m/n;
        if(m%n!=0){
            cout << " " << m%n/num << "/" << n/num; 
        }
    }else{
        if(m==0) cout << 0;
        else{
            cout << m%n/num << "/" << n/num;
        }
    }
    if(m<0){
        cout << ")";
    }
    cout << endl;


    return 0;
}