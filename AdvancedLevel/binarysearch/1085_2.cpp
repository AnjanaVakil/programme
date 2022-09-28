#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//AC
int main()
{
    int n;
    long long p;
    cin >> n >> p;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    int result=0;
    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=i+result;j<n;j++){
            if(num[j]<=num[i]*p){
                temp=j-i+1;
                if(temp>result){
                    result=temp;
                }
            }else{
                break;
            }
        }
    }
    cout << result;
    return 0;
}