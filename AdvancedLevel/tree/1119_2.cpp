#include<iostream>
#include<vector>
using namespace std;
bool uni=true;
vector<int> pre,post,in;
void getIn(int preL,int preR,int postL,int postR)
{
    if(preL>preR) return;
    int root_data=pre[preL];
    if(preL==preR){
        in.push_back(root_data);
        return;
    }
    int i=preL+1;
    while(i<=preR && pre[i]!=post[postR-1]) i++;
    int numLeft=i-(preL+1);
    if(numLeft>0){
        getIn(preL+1,i-1,postL,postL+numLeft-1);
    }else{
        uni=false;
    }
    in.push_back(post[postR]);
    getIn(i,preR,postL+numLeft,postR-1);
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
    if(uni){
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