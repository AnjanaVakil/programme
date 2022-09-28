#include<iostream>
using namespace std;
//12'
bool isIegal(string s)
{
    for(int i=0;i<s.length();i++){
        if(!(isdigit(s[i]) || s[i]=='.' || s[i]=='-')) return false;
    }
    //stirng转double stod
    double num=stod(s);
    if(num<(-1000.0) || num>1000.0) return false;
    int index=s.find('.');
    string frac=s.substr(index+1);
    if(!(frac.length()==1 || frac.length()==2)){
        return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    string s;
    double avg=0.0;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin >> s;
        if(isIegal(s)){
            cnt++;
            avg+=stod(s);
        }else{
            cout << "ERROR: " << s << " is not a legal number\n";
        }
    }
    if(cnt==1){
        printf("The average of %d number is %.2f",cnt,avg);
    }else if(cnt==0){
        printf("The average of 0 number is Undefined");
    }else{
        avg/=cnt;
        printf("The average of %d numbers is %.2f",cnt,avg);
    }
    return 0;
}