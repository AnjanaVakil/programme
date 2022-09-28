#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//14:28-45 25score
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    //10
    //23 8 10 99 46 2333 46 1 666 555
    //1 8 10 23 46 46 99   555 666 2333
    sort(v.begin(),v.end());
    int s1=0,s2=0;
    int len=v.size();
    for(int i=0;i<len/2;i++){
        s1+=v[i];
    }
    for(int i=len/2;i<len;i++){
        s2+=v[i];
    }
    printf("%d %d",len%2,abs(s1-s2));
    return 0;
}