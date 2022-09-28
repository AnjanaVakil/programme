#include<iostream>
#include<cstring>
using namespace std;
//12:50-13:18
//N执行操作100次(K<=100)以后，已经远超过long long的表示范围，必须用大整数运算
struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};
bool isPalin(bign a)
{
    for(int i=0;i<a.len;i++){
        if(a.d[i]!=a.d[a.len-i-1]) return false;
    }
    return true;
}
bign change(string s)
{
    bign c;
    c.len=s.length();
    for(int i=0;i<c.len;i++){
        c.d[i]=s[c.len-i-1]-'0';
    }
    return c;
}
void printBign(bign c)
{
    for(int i=c.len-1;i>=0;i--){
        cout << c.d[i];
    }
}
bign add(bign a)
{
    //reverse
    bign b;
    b.len=a.len;
    for(int i=0;i<b.len;i++){
        b.d[i]=a.d[a.len-i-1];
    }
    bign c;
    int carry=0;
    for(int i=0;i<a.len || i<b.len;i++){
        carry+=a.d[i]+b.d[i];
        c.d[c.len++]=carry%10;
        carry/=10;
    }
    //注意这里是if，if和while一定要注意用对!
    if(carry){
        c.d[c.len++]=carry;
    }
    return c;
}
int main()
{
    string s;
    int k;
    cin >> s >> k;
    bign a=change(s);
    int step=0;
    while(k--){
        if(isPalin(a)){
            break;
            // printBign(a);
            // cout << "\n" << step;
            // return 0;
        }else{
            a=add(a);
            step++;
        }
    }
    printBign(a);
    cout << "\n" << step;
    return 0;
}