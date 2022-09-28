#include<iostream>
#include<algorithm>
using namespace std;
//有一个测试用例注意点，如果当输入N值为6174的时候，依旧要进行下面的步骤，直到差值为6174才可以～
//所以用do while语句，无论是什么值总是要执行一遍while语句，直到遇到差值是0000或6174～
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    string s;
    cin >> s;
    s.insert(0,4-s.length(),'0');
    do{
        string a=s,b=s;
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end());
        int res=stoi(a)-stoi(b);
        s=to_string(res);
        s.insert(0,4-s.length(),'0');
        cout << a << " - " << b << " = " << s << endl;
    }while(s!="0000" && s!="6174");
    return 0;
}