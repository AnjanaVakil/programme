#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vector<int> liars,tag(n+1,1);
            //tag: 1:human -1:wolf
            tag[i]=tag[j]=-1;
            for(int k=1;k<=n;k++){
                if(v[k]*tag[abs(v[k])]<0) liars.push_back(k);
            }
            if(liars.size()==2 && tag[liars[0]]+tag[liars[1]]==0){
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}