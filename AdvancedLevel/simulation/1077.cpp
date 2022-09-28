#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//15:20-45 25min 未做出来 
//其实大概思路都对了，只要再认真修改下
//最长公共后缀
int main()
{
    int n;
    // cin >> n;
    // getchar();//读取换行符，否则字符串读取错误
    scanf("%d\n",&n);//这个多加一个\n,就不用加getchar()
    string s,res;
    vector<string> v;
    int minLen=256;
    for(int i=0;i<n;i++){
        getline(cin,s);
        reverse(s.begin(),s.end());
        if(s.length()<minLen){
            minLen=s.length();
        }
        v.push_back(s);
    }
    for(int j=0;j<minLen;j++){
        bool same=true;
        char t=v[0][j];
        for(int i=1;i<n;i++){
            if(v[i][j]!=t){
                same=false;
                break;
            }
        }
        //都相等
        if(same==true){
            res+=t;
        }else{
            break;
        }
    }
    if(res!=""){
        for(int i=res.length()-1;i>=0;i--){
            cout << res[i];
        }
    }else{
        cout << "nai";
    }
    return 0;
}