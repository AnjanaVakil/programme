#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int n;
        cin >> n;
        bool result=true;
        vector<int> q(n);
        for(int j=0;j<n;j++){
            cin >> q[j];
            for(int t=0;t<j;t++){
                if(q[t]==q[j] || abs(q[j]-q[t])==abs(j-t)){
                    result=false;
                    break;
                }
            }
        }
        cout << (result==true?"YES\n":"NO\n");
    }
    return 0;
}