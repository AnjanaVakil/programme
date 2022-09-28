#include<iostream>
#include<cstring>
using namespace std;
struct bign{
    int d[25];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};
int hashTable[10]={0};
bign change(string s)
{
    bign c;
    c.len=s.length();
    for(int i=0;i<c.len;i++){
        c.d[i]=s[c.len-i-1]-'0';
    }
    return c;
}
bign multi(bign a,int b)
{
    bign c;
    int carry=0;
    for(int i=0;i<a.len;i++){
        int temp=a.d[i]*b+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    while(carry){
        c.d[c.len++]=carry%10;
        carry/=10;
    }
    return c;
}
void printBign(bign a)
{
    for(int i=a.len-1;i>=0;i--){
        cout << a.d[i];
    }
}
bool judge(bign c)
{
    for(int i=c.len-1;i>=0;i--){
        if(hashTable[c.d[i]]==0) return false;
        else hashTable[c.d[i]]-=1;
    }
    return true;
}
int main()
{
    string s;
    cin >> s;
    bign a=change(s);
    for(int i=0;i<a.len;i++){
        hashTable[a.d[i]]+=1;
    }
    bign c=multi(a,2);
    if(judge(c)){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    //Then in the next line, print the doubled number.认真读题！
    printBign(c);
    return 0;
}