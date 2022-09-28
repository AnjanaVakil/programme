#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(string a,string b)
{
    //不是按照字典序排列就可以的
    //必须保证两个字符串构成的数字是最小的才行
    return a+b < b+a;
}
string str[10010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin >> str[i];
    }
    sort(str,str+n,cmp);
    // for(int i=0;i<v.size();i++){
    //     cout << v[i] << " ";
    // }
    string res;
    for(int i=0;i<n;i++){
        res+=str[i];
    }
    //Notice that the first digit must not be zero.
    //所以开头可能不止一个0，一定不要局限在给定的sample中
    //所以这里应该使用while，而不是if
    while(res.length()!=0 && res[0]=='0'){
        res.erase(res.begin());
    }
    if(res.length()==0) cout << 0;
    cout << res;
    return 0;
}