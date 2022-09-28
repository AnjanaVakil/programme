#include<iostream>
#include<vector>
using namespace std;
//10进制-->b进制
//除基取余法 
vector<int> decimalToBase(int n,int b)
{
    vector<int> res;
    while(n){
        res.push_back(n%b);
        n/=b;
    }
    return res;
}
int main()
{
    int n,b;
    cin >> n >> b;
    vector<int> res=decimalToBase(n,b);
    int flag=0;
    int len=res.size();
    for(int i=0;i<len/2;i++){
        if(res[i]!=res[len-i-1]){
            cout << "No\n";
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout << "Yes\n";
    }
    for(int i=len-1;i>=0;i--){
        if(i!=len-1) cout << " ";
        cout << res[i];
    }
    return 0;
}