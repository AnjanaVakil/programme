#include<iostream>
using namespace std;
int main()
{
    char c;
    cin >> c;
    string s;
    getchar();
    getline(cin,s);
    //不管是压缩还是解压，自身都需要输出
    //初始化cnt的值为1
    int cnt=1;
    if(c=='C'){
        for(int i=0;i<s.length();i++){
            while(s[i]==s[i+1]){
                cnt++;
                i++;
            }
            if(cnt>=2) cout << cnt;
            cout << s[i];
            cnt=1;
        }
    }else{
        string num;
        //题目保证字符重复个数在整型范围内
        //所以会有连着几位都是数字的情况，这时候就不能一位一位判断了
        //可以将数字存储在string num中，然后转换为数字就可以输出了
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                num+=s[i];
            }else{
                if(num.length()>0) cnt=stoi(num);
                while(cnt--) cout << s[i];
                cnt=1;
                num="";
            }
        }
    }
    return 0;
}