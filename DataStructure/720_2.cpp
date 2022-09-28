#include<iostream>
#include<string.h>
#include<stack>
#include<queue>
#include<cmath>

#define mem(a,b) memset(a,b,sizeof a);
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;

int main()
{
    stack<string> opsk;
    queue<string> rsqe;
    while(!opsk.empty()) opsk.pop();
    while(!rsqe.empty()) rsqe.pop();

    char s[50]; scanf("%s",s);
    int len=strlen(s),num=0;
    for(int i=0;i<len;i++)
    {
        string ts="";
        char c=s[i], prc=s[i-1];
        // 处理数据，支持 double
        if((c=='+' || c=='-') && (!i || prc=='(') || (c>='0' && c<='9'))
        {
            if(c!='+') ts+=c;
            while(s[i+1]=='.' || s[i+1]>='0' && s[i+1]<='9')
                ts+=s[++i];
            rsqe.push(ts);
        }
        else if(c=='+' || c=='-')
        {
            int flag=1;
            while(flag)
            {
                if(opsk.empty() || opsk.top()=="(")
                    opsk.push(ts+c), flag=0;
                else // tp == + - * /
                {
                    rsqe.push(opsk.top());
                    opsk.pop();
                }
            }
        }
        else if(c=='*' || c=='/')
        {
            int flag=1;
            while(flag)
            {
                if(opsk.empty() || opsk.top()=="(" || opsk.top()=="+" || opsk.top()=="-")
                    opsk.push(ts+c), flag=0;
                else // tp == * /
                {
                    rsqe.push(opsk.top());
                    opsk.pop();
                }
            }
        }
        else if(c=='(')
            opsk.push(ts+c);
        else if(c==')')
        {
            int flag=1;
            while(flag)
            {
                string tp=opsk.top();
                if(tp=="(") opsk.pop(), flag=0;
                else
                {
                    rsqe.push(opsk.top());
                    opsk.pop();
                }
            }
        }
    }

    while(!opsk.empty())
    {
        rsqe.push(opsk.top());
        opsk.pop();
    }

    if(!rsqe.empty()){ printf("%s",rsqe.front().c_str()); rsqe.pop(); }
    while(!rsqe.empty())
    {
        printf(" %s",rsqe.front().c_str()); rsqe.pop();
    }
    puts("");

    return 0;
}