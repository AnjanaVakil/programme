#include<iostream>
#include<stack>
using namespace std;
//中缀转后缀
string translate(string medium)
{
    string rear="";
    stack<char> sign;
    for(int i=0;i<medium.length();i++){
        if(isdigit(medium[i])){
            rear+=medium[i];
            rear+=' ';
        }else if(medium[i]=='('){
            sign.push('(');
        }else if(medium[i]==')'){
            while(sign.top()!='('){
                rear+=sign.top();
                sign.pop();
            }
            if(sign.top()=='('){
                sign.pop();
            }
        }else{
            if(medium[i]=='*' || medium[i]=='/'){
                sign.push(medium[i]);
            }else if(medium[i]=='+' || medium[i]=='-'){
                char top=sign.top();
                while(top=='*' || top=='/' || top=='+' || top=='-'){
                    rear+=top;
                    rear+=' ';
                    sign.pop();
                    top=sign.top();
                }
                sign.push(medium[i]);
            }
        }
    }
    while(!sign.empty()){
        rear+=sign.top();
        rear+=' ';
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