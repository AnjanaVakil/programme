#include<iostream>
using namespace std;
struct multiply{
    int full,option,right;
    string allright;
};
//自己没写出来
int main()
{
    int n,m;
    cin >> n >> m;
    string answer;
    multiply mul[101];
    for(int i=0;i<m;i++){
        cin >> mul[i].full >> mul[i].option >> mul[i].right;
        getline(cin,mul[i].allright);
    }
    for(int i=0;i<n;i++){
        double res=0;
        for(int j=0;j<m;j++){
            getchar();
            cin >> answer;
            int temp=answer.find('(');
            if(answer[temp+1]-'0'==mul[i].right && answer.substr(temp+3,answer.length()-2)==mul[i].allright){
                res+=mul[i].full;
            }else if(answer[temp+1]-'0'<mul[i].right){
                int flag=1;
                for(int k=3;k<answer.length()-1;k++){
                    for(int l=0;l<mul[i].allright.length();l++){
                        if(answer[k]!=mul[i].allright[k]){
                            flag=0;
                        }
                    }
                }
                if(flag) res+=mul[i].full*1.0/2;
            }
        }
        cout << res << endl;
    }

    return 0;
}