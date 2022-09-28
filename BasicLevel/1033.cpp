#include<iostream>
using namespace std;
int main()
{
    string a,b;
    //cin >> a >> b;会一个答案错误
    //如果没有一个字符能被打出，则输出空行。
    getline(cin,a);
    getline(cin,b);
    int j=0;
    while(j<b.length()){
        if(a.find(toupper(b[j]))==string::npos){
            if(b[j]>='A' && b[j]<='Z'){
                if(a.find('+')==string::npos){
                    cout << b[j];
                }
            }else{
                cout << b[j];
            }
        }
        j++;
    }
}