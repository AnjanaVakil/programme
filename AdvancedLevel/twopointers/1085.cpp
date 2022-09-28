#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    long long p;
    cin >> n >> p;
    vector<long long> seq(n);
    for(int i=0;i<n;i++){
        cin >> seq[i];
    }
    sort(seq.begin(),seq.end());
    // for(int i=0;i<n;i++){
    //     cout << seq[i] << " ";
    // }
    // cout << endl;
    int i=0,j=0,count=1;
    while(i<n && j<n){
        while(j<n && seq[j]<=seq[i]*p){
            count=max(count,j-i+1);
            j++;
        }
        i++;
    }
    cout << count;
    return 0;
}