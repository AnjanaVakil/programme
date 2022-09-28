#include<iostream>
#include<vector>
using namespace std;
// const int N=100010;
const int N=1e5+5;
int main()
{
    int n,num;
    cin >> n;
    vector<int> hash(N,0);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        if(num>0 && num<=N){
            hash[num]=1;
        }
    }
    for(int i=1;i<=N;i++){
        if(hash[i]==0){
            printf("%d",i);
            break;
        }
    }
    return 0;
}