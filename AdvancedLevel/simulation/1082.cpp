#include<iostream>
#include<vector>
using namespace std;
//16:36-17:30 12‘
string read[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
    //10^9 2^30 2^32
    string s,res;
    cin >> s;
    if(s[0]=='-'){
        res+="Fu ";
        s=s.substr(1);
    }
    // cout << s << endl;
    int len=s.length();
    if(len==9){
        res+=read[s[0]-'0']+" Yi ";
        s=s.substr(1);
    }
    // cout << s << endl;
    len=s.length();
    if(len<9 && len>4){
        string temp=s.substr(0,len-4);
        // cout << temp << endl;
        int tempLen=temp.length();
        int index;
        switch(tempLen){
            case 4:{
                index=tempLen-4;
                if(temp[index]!='0'){
                    res+=read[temp[index]-'0']+" Qian ";
                }else if(temp[index+1]!=0){
                    res+=" ling";
                }
            }
            case 3:{
                index=tempLen-3;
                if(temp[index]!='0'){
                    res+=read[temp[index]-'0']+" Bai ";
                }else if(temp[index+1]!=0){
                    res+=" ling";
                }
            }
            case 2:{
                index=tempLen-2;
                if(temp[index]!='0'){
                    res+=read[temp[index]-'0']+" Shi ";
                }else if(temp[index+1]!=0){
                    res+=" ling";
                }
            }
            case 1:{
                index=tempLen-1;
                if(temp[index]!='0'){
                    res+=read[temp[index]-'0']+" ";
                }
            }
        }
        res+="Wan ";
        s=s.substr(temp.length());
    }
    // cout << s << endl;
    len=s.length();
    if(len<=4){
        int index;
        switch(len){
            case 4:{
                index=len-4;
                if(s[index]!='0'){
                    res+=read[s[index]-'0']+" Qian ";
                }else if(s[index+1]!='0'){
                    res+="ling ";
                }
            }
            case 3:{
                index=len-3;
                if(s[index]!='0'){
                    res+=read[s[index]-'0']+" Bai ";
                }else if(s[index+1]!=0){
                    res+=" ling";
                }
            }
            case 2:{
                index=len-2;
                if(s[index]!='0'){
                    res+=read[s[index]-'0']+" Shi ";
                }else if(s[index+1]!=0){
                    res+=" ling";
                }
            }
            case 1:{
                index=len-1;
                if(s[index]!='0'){
                    res+=read[s[index]-'0'];
                }
            }
        }
    }
    cout << res;
    return 0;
}