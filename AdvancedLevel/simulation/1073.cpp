#include<iostream>
#include<cctype>
using namespace std;
//20:05-20:30 7' -40 9' 第二天花了5min，改正了小错误 20‘
//一定要认真读题目！！！因为是英文题目，自己忙着敲代码，而不认真读题，这种做法不可取！！！
//题目中都说了，which means that the integer portion has exactly one digit
//数字的整数部分只有1位(scientific notation)
//觉得困难做不下去没思路或者找不到错误的时候应该先放放，可以第二天再思考
int main()
{
    string s;
    cin >> s;
    if(s[0]=='-'){
        cout << "-";
    }
    if(!isdigit(s[0])){
        s=s.substr(1);
    }
    // cout << s << endl;
    int a=s.find('.');
    //按照小数点来分也太麻烦了，直接按照E来分即可
    // cout << a << endl;
    string fract=s.substr(0,a);
    // cout << fract << endl;
    int Epos=s.find('E');
    int n=Epos-a-1;
    string num=s.substr(a+1,n);
    // cout << num << endl;
    string expon=s.substr(Epos+1);
    // cout << expon << endl; //+10
    int exponNum=stoi(expon);
    if(exponNum>0){
        cout << fract;
        if(num.length()>exponNum){
            int i;
            for(i=0;i<exponNum;i++){
                cout << num[i];
            }
            cout << ".";
            for(;i<num.length();i++){
                cout << num[i];
            }
        }else{
            int zero=exponNum-num.length();
            cout << num;
            for(int i=0;i<zero;i++){
                cout << 0;
            }
        }
    }else{
        exponNum=abs(exponNum);
        if(fract.length()<exponNum){
            int zero=exponNum-fract.length();
            cout << "0.";
            for(int i=0;i<zero;i++){
                cout << 0;
            }
            cout << fract << num;
        }else{
            int len=fract.length()-exponNum;
            int i;
            for(i=0;i<len;i++){
                cout << fract[i];
            }
            cout << ".";
            for(;i<fract.length();i++){
                cout << fract[i];
            }
            cout << num;
        }
    }
    // cout << stoi("-10") << endl; //-10
    // cout << stoi("+10") << endl; //+10
    return 0;
}