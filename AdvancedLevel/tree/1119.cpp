#include<iostream>
#include<vector>
using namespace std;
bool unique1=true;
vector<int> pre,post,in;
void getIn(int preL,int preR,int postL,int postR)
{
    if(preL==preR){
        in.push_back(pre[preL]);
        return;
    }
    if(pre[preL]==post[postR]){
        int i=preL+1;
        while(i<=preR && pre[i]!=post[postR-1]) i++;
        if(i-preL>1){
            getIn(preL+1,i-1,postL,postL+(i-preL-1)-1);
        }else{
            unique1=false;
        }
        in.push_back(post[postR]);
        getIn(i,preR,postL+(i-preL-1),postR-1);
    }
}
int main()
{
    int n;
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for(int i=0;i<n;i++){
        cin >> pre[i];
    }
    for(int i=0;i<n;i++){
        cin >> post[i];
    }
    getIn(0,n-1,0,n-1);
    if(unique1){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    cout << in[0];
    for(int i=1;i<in.size();i++){
        cout << " " << in[i];
    }
    cout << endl;
    return 0;
}