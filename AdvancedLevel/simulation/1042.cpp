// S3, H5, C1, D13 and J2 
// {4, 2, 5, 3, 1}
// J2, H5, D13, S3, C1
// {4, 2, 5, 3, 1}
// C1 H5 S3 J2 D13
//12:50-13:15 未做出来
#include<iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int order[55],start[55],end[55];
    for(int i=1;i<=54;i++){
        cin >> order[i];
        start[i]=i;
    }
    for(int i=0;i<k;i++){
        for(int j=1;j<=54;j++){
            end[order[j]]=start[j];
        }
        for(int j=1;j<=54;j++){
            start[j]=end[j];
        }
    }
    string s="SHCDJ";
    for(int i=1;i<=54;i++){
        end[i]-=1;
        cout << s[end[i]/13] << end[i]%13+1;
        if(i!=54) cout << " ";
    }
    return 0;
}