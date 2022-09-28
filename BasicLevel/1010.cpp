#include<iostream>
using namespace std;
int main()
{
    int a,b,flag=0;
    while(cin >> a >> b){
        if(b!=0){
            if(flag==1) cout<< " ";
            cout << a*b << " " << b-1;
            flag=1;
        }
        //这一行可加可不加,答案正确
        // if(cin.get()=='\n') break;
    }
    //这一行很重要,说明不能忘记题目中的描述
    if(flag==0) cout<< "0 0";
    return 0;
}