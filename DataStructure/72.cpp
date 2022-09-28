#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m,n;
    cin >> m;
    vector<int> a(m),b(m),c(n),d(n),p(1000000,0);
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i];
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c[i] >> d[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int t=b[i]+d[j];
            p[t]+=(a[i]*c[j]);
        }
    }
    int flag1=0;
    for(int i=1000000;i>=0;i--){
        if(p[i]){
            if(flag1) cout << " ";
            cout << p[i] << " " << i;
            flag1=1;
        }
    }
    if(m!=0 && n!=0){
        cout << "\n";
    }
    int flag2=0;
    int num=m>n?m:n;
    int i=0,j=0;
    while(i<m || j<n){
        if(b[i]>d[j]){
            if(flag2) cout << " ";
            cout << a[i] << " " << b[i];
            flag2=1;
            i++;
        }else if(b[i]<d[j]){
            if(flag2) cout << " ";
            cout << c[j] << " " << d[j];
            flag2=1;
            j++;
        }else{
            if(flag2) cout << " ";
            cout << a[i]+c[j] << " " << b[i];
            flag2=1;
            i++;
            j++;
        }
    }

    if(m==0 && n==0){
        cout << "0 0";
    }
    return 0;
}