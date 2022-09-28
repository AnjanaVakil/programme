#include<iostream>
#include<stack>
using namespace std;
//22'
const int maxn=100010;
struct Node{
    char data;
    int next;
}node[maxn];
int main()
{
    int a,b,n;
    cin >> a >> b >> n;
    int add;
    for(int i=0;i<n;i++){
        cin >> add;
        cin >> node[add].data >> node[add].next;
    }
    int temp=a;
    int lena=0;
    stack<char> stk1,stk2;
    while(a!=-1){
        stk1.push(node[a].data);
        a=node[a].next;
        lena++;
    }
    while(b!=-1){
        stk2.push(node[b].data);
        b=node[b].next;
    }
    int cnt=0;
    while(!stk1.empty() && !stk2.empty()){
        if(stk1.top()==stk2.top()){
            stk1.pop();
            stk2.pop();
            cnt++;
        }else{
            break;
        }   
    }
    cnt=lena-cnt;
    while(temp!=-1 && cnt!=0){
        temp=node[temp].next;
        cnt--;
    }
    if(temp!=-1){
        printf("%05d",temp);
    }else{
        printf("-1");
    }
    return 0;
}