#include<iostream>
using namespace std;
//自己并没有写出来,下次应该多读几次题目
//思考很久后还不会的话看大神的思路,然后尝试自己写代码
//照着别人的代码写永远不会有进步的
string a[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void MarsToEarth(int t)
{
    if(t/13) cout << b[t/13];
    if((t/13) && (t%13)) cout << " ";
    if(t%13 || t==0) cout << a[t%13];
}
void EarthToMars(string input)
{
    int t1=0,t2=0;
    string s1=input.substr(0,3),s2;
    if(input.length()>4){
        s2=input.substr(4,3);
    }
    for(int i=1;i<=12;i++){
        if(s1==a[i] || s2==a[i]) t2=i;
        if(s1==b[i]) t1=i;
    }
    cout << t1*13+t2;
}
int main()
{
    //29/13=1 29%13=3
    //115/13=8 115%13=11
    //每行给出一个 [0, 169) 区间内的数字 
    //或者是地球文，或者是火星文。
    //所以火星文的位数最多为2位
    int n;
    cin >> n;
    getchar();
    string input;
    while(n--){
        getline(cin,input);
        if( isdigit(input[0]) ){
            MarsToEarth(stoi(input));
        }else{
            EarthToMars(input);
        }
        cout << endl;
    }
    return 0;
}