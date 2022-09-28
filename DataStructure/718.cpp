#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int N,id,flag=0;
    cin >> N;
    queue<int> a,b;
    for(int i=0;i<N;i++){
        cin >> id;
        if(id%2!=0){
            a.push(id);
        }else{
            b.push(id);
        }
    }
    for(int i=0;i<N;i++){
        if(!a.empty()){
            if(flag){
                cout << " ";
            }
            flag=1;
            cout << a.front();
            a.pop();
            if(!a.empty()){
                cout << " " <<  a.front();
                a.pop();
            }
        }
        if(!b.empty()){
            if(flag){
                cout << " ";
            }
            flag=1;
            cout << b.front();
            b.pop();
        }
    }
    return 0;
}