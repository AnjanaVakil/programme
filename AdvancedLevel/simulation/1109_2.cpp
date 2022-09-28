#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//22:00-47 25'
struct node{
    string name;
    int height;
};
bool cmp(node a,node b)
{
    //height降序no-increase 大的放在小的前面 >
    //name升序increase 小的放在大的前面 <
    return a.height!=b.height?a.height>b.height:a.name<b.name;
}
int main()
{
    int n,k;
    cin >> n >>  k;
    string name;
    int height;
    vector<node> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].name >> v[i].height;
    }
    sort(v.begin(),v.end(),cmp);
    int index=0;
    int row;
    vector<string> res;
    for(int i=0;i<k;i++){
        //注意，这个每行的结果都不一样，初始化要放在循环里面
        if(i==0) row=n/k+n%k;
        else row=n/k;
        res.resize(row);
        res[row/2]=v[index].name;
        int j=row/2-1;
        for(int i=index+1;i<index+row;i+=2){
            res[j--]=v[i].name;
        }
        j=row/2+1;
        for(int i=index+2;i<index+row;i+=2){
            res[j++]=v[i].name;
        }
        for(int i=0;i<res.size();i++){
            if(i!=0) cout << " ";
            cout << res[i];
        }
        cout << "\n";
        index=index+row;
    }
    return 0;
}