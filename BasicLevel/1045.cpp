#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//0'
int main()
{
    int n;
    cin >> n;
    vector<int> a(n),temp(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int flag=1,t=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            for(int k=0;k<i;k++){
                if(a[k]>a[i]){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1){
            temp[t++]=a[i];
        }
    }
    cout << t << endl;
    sort(temp.begin(),temp.end());
    for(int i=0;i<t;i++){
        if(i!=0) cout << " ";
        cout << temp[i];
    }
    return 0;
}