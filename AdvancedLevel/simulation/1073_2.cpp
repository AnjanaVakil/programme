#include<iostream>
#include<cctype>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s[0]=='-'){
        cout << '-';
    }
    //按照小数点来分也太麻烦了，直接按照E来分即可
    int Epos=s.find('E');
    string fract=s.substr(1,Epos-1);
    // cout << fract << endl;
    string expon=s.substr(Epos+1);
    // cout << expon << endl; //+10
    int exponNum=stoi(expon);
    if(exponNum>0){
        cout << fract[0];
        int i,cnt;
        for(i=2,cnt=0;cnt<exponNum && i<fract.length();i++,cnt++){
            cout << fract[i];
        }
        if(i==fract.length()){
            int zero=exponNum-cnt;
            for(int j=0;j<zero;j++){
                cout << 0;
            }
        }else{
            cout << ".";
            for(int j=i;j<fract.length();j++){
                cout << fract[j];
            }
        }
    }else{
        cout << "0.";
        int zero=abs(exponNum)-1;
        for(int i=0;i<zero;i++){
            cout << 0;
        }
        for(int i=0;i<fract.length();i++){
            if(fract[i]!='.'){
                cout << fract[i];
            }
        }
    }
    return 0;
}