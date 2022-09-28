#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> v;
bool isprime(int n)
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
    int n,maxp;
    cin >> n >> maxp;
    for(int i=3;i<maxp;i+=2){
        if(isprime(i)){
            v.push_back(i);
        }
    }
    if(n>v.size()){
        cout << v[v.size()-1];
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            int diff=v[j]-v[i];
            if(v[j]+diff==v[j+1]){
                continue;
            }else{
                break;
            }
        }
    }
    return 0;
}