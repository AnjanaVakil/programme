#include<iostream>
#include<cmath>
using namespace std;
//23-39 19'
bool isPrime(int n)
{
    if(n<=1) return false;
    int sqr=(int)sqrt(n*1.0);
    for(int i=2;i<=sqr;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int l,k;
    string s;
    cin >> l >> k >> s;
    //i<=l-k 不能写成i<=s.length()-k
    //comparison between signed and unsigned integer expressions
    for(int i=0;i<=l-k;i++){
        string temp=s.substr(i,k);
        if(isPrime(stoi(temp))){
            cout << temp;
            return 0;
        }
    }
    cout << "404\n";
    return 0;
}