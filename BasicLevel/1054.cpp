#include<iostream>
using namespace std;
bool is_legal(string s)
{
    int i=0;
    int len=s.length();
    while(i<len){
        if(!isdigit(s[i]) && s[i]!='.' && s[i]!='-')
            return false;
        if(s[i]=='.'){
            int t=len-i-1;
            if(t>2){
                return false;
            }
        }
        i++;
    }
    float num=stof(s.c_str());
    if(num<-1000 || num>1000) return false;
    return true;
}
int main()
{
    int n,cnt=0;
    cin >> n;
    string s;
    float avg=0;
    for(int i=0;i<n;i++){
        cin >> s;
        if(is_legal(s)){
            avg+=(atof(s.c_str()));
            cnt++;
        }else{
            cout << "ERROR: " << s << " is not a legal number\n";
        }
    }
    avg/=cnt;
    cout << "The average of ";
    if(cnt==0){
        printf("0 numbers is Undefined");
    }else if(cnt==1){
        //The average of 1 number is ”这句话。这个number不能带有s
        printf("%d number is %.2f",cnt,avg);
    }else{
        printf("%d numbers is %.2f",cnt,avg);
    }
    return 0;
}