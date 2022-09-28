#include<iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s[0]=='-') cout << '-';
    int i=s.find('E');
    string a=s.substr(1,i-1);
    string b=s.substr(i+1,s.length()-1);
    int n=stoi(b);
    if(n<0){
        cout << "0.";
        for(int i=0;i<((-n)-1);i++){
            cout << '0';
        }
        for(int i=0;i<a.length();i++){
            if(a[i]!='.') cout << a[i];
        }
    }else {
        //n>0的情况不能再这样写了
        //-1.22343423E+3 
        //-122343423% 
        // for(int i=0;i<a.length();i++){
        //     if(a[i]!='.') cout << a[i];
        // }
        // for(int i=a.length()-1;i<n;i++){
        //     cout << '0';
        // }
        //借鉴别人的写法
        cout << a[0];
        int j,cnt;
        for(j=2,cnt=0;j<a.length() && cnt<n;j++,cnt++){
            cout << a[j];
        }
        if(j==a.length()){
            for(int k=0;k<n-cnt;k++) cout << '0';
        }else{
            cout << '.';
            for(int k=j;k<a.length();k++) cout << a[k];
        }
    }
    return 0;
}