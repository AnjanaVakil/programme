#include<iostream>
#include<stack>
using namespace std;
int compare(char a,char b)
{
    if(b==')') return 1;
    if(b=='(' || a=='(') return 0;
    switch(b){
        case '+':
        case '-':return 1;break;
        case '*':
        case '/':switch(a){
            case '+':
            case '-':return 0;break;
            case '*':
            case '/':return 1;break;
        }
    }
}
int isNum(char c)
{
    return isdigit(c) || c=='.';
}
int isPlusOrMinus(char c)
{
    return c=='+' || c=='-';
}
//中缀转后缀
string translate(string medium)
{
    string rear="";
    stack<char> sign;
    int first=0;
    for(int i=0;i<medium.length();i++){
        if(isNum(medium[i])){
            if(first){
                rear+=' ';
            }
            first=1;
            rear+=medium[i];
        }else if(isPlusOrMinus(medium[i]) && (i? !isNum(medium[i-1]) && medium[i-1]!=')':1) ){
            if(medium[i]=='-'){
                if(first){
                    rear+=' ';
                }
                first=1;
                rear+=medium[i];
            }
        }else{
            if(sign.top()){
                if(medium[i]==')'){
                    while(sign.top()){
                        if(sign.top()=='(') break;
                        if(first){
                            rear+=' ';
                        }
                        first=1;
                        rear+=sign.top();
                        sign.pop();
                    }
                }
                else{
                    while(sign.top()){
                        //medium[i]优先级低
                        if(compare(sign.top(),medium[i])){
                            if(first){
                                rear+=' ';
                            }
                            first=1;
                            rear+=sign.top();
                        }else{
                            break;
                        }
                    }
                    sign.push(medium[i]);
                }
            }else{
                sign.push(medium[i]);
            }
        }
    }
    while(!sign.empty()){
        if(first){
            rear+=' ';
        }
        first=1;
        rear+=sign.top();
        sign.pop();
    }
    return rear;
}
int main()
{
    string s;
    cin >> s;
    cout << translate(s);
    return 0;
}