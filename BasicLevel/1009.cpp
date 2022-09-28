#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    vector<string> v;
    while(cin >> s){
        v.push_back(s);
        if(cin.get()=='\n') break;
    }
    //输出的v全部写成了s,导致每次只输出一个字母
    //问题排查花了不少时间,认真啊
    for (int i = v.size() - 1; i > 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << v[0];
    return 0;
}