#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main() 
{
    int n;
    cin >> n;
    vector<int> dis(n);
    for(int i=0;i<n;i++){
        cin >> dis[i];
    }
    sort(dis.begin(),dis.end(),cmp);
    int e=0;
    while(e<n && dis[e]>e+1) e++;
    cout << e;
    return 0;
}