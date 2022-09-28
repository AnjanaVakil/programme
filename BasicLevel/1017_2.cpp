#include<iostream>
#include<cstring>
using namespace std;
struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};
bign divide(bign a,int b,int &r)
{
    bign c;
    c.len=a.len;
    for(int i=a.len-1;i>=0;i--){
        //余数
        r=r*10+a.d[i];
        if(r<b){
            c.d[i]=0;
        }
        else{
            c.d[i]=r/b;
            r=r%b;
        }
    }
    while(c.len>1 && c.d[c.len-1]==0){
        c.len--;
    }
    return c;
}
int main()
{
    string s;
    int b;
    cin >> s >> b;
    bign a;
    a.len=s.length();
    for(int i=0;i<s.length();i++){
        a.d[i]=s[a.len-i-1]-'0';
    }
    int r=0;
    bign c=divide(a,b,r);
    for(int i=c.len-1;i>=0;i--){
        cout << c.d[i];
    }
    cout << " " << r;
    return 0;
}