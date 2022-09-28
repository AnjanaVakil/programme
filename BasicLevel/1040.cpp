#include<iostream>
using namespace std;
int main()
{
    //1 000 000 007 
    string s;
    cin >> s;
    int res=0,numT=0,numAT=0,numPAT=0;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='T'){
            numT++;
        }
        else if(s[i]=='A'){
            numAT=(numAT+numT)%1000000007; 
        }
        else{
            numPAT=(numPAT+numAT)%1000000007;
        }
    }
    cout << numPAT;
    return 0;
}