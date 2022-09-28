#include<iostream>
#include<cmath>
#include<map>
using namespace std;
const int maxn=10010;
int book[maxn]={0};
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
    int n;
    cin >> n;
    map<int,int> ranklist;
    for(int i=0;i<n;i++){
        int id;
        cin >> id;
        ranklist[id]=i+1;
    }
    int k;
    cin >> k;
    int query;
    for(int i=0;i<k;i++){
        cin >> query;
        if(book[query]==1){
            printf("%04d: Checked\n",query);
            continue;
        }else{
            if(ranklist.find(query)==ranklist.end()){
                printf("%04d: Are you kidding?\n",query);
            }else{
                book[query]=1;
                if(ranklist[query]==1){
                    printf("%04d: Mystery Award\n",query);
                }else if(isPrime(ranklist[query])){
                    printf("%04d: Minion\n",query);
                }else{
                    printf("%04d: Chocolate\n",query);
                }
            }
        }
    }
}