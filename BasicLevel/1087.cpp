#include<iostream>
#include<set>
using namespace std;
int main()
{
    // int n;
    // cin >> n;
    // set<int> s;
    // for(int i=1;i<=n;i++){
    //     s.insert(i/2+i/3+i/5);
    // }
    // cout << s.size();
    int n;
    cin >> n;
    int num[100001]={0},cnt=0;
    for(int i=1;i<=n;i++){
        int temp=i/2+i/3+i/5;
        if(num[temp]==0){
            cnt++;
            num[temp]=1;
        }
    }
    cout << cnt;
    return 0;
}