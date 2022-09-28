#include<iostream>
using namespace std;
int main()
{
    //S3, H5, C1, D13 and J2
    //{4, 2, 5, 3, 1}
    //J2 H5 D13 S3 C1
    int k;
    int order[55],start[55],end[55];
    cin >> k;
    for(int i=1;i<=54;i++){
        cin >> order[i];
        end[i]=i;
    }
    for(int i=0;i<k;i++){
        for(int j=1;j<=54;j++){
            start[j]=end[j];
        }
        for(int j=1;j<=54;j++){
            end[order[j]]=start[j];
        }
    }
    string s="SHCDJ";
    for(int i=1;i<=54;i++){
        if(i!=1) cout << " ";
        end[i]=end[i]-1;
        cout << s[end[i]/13] << end[i]%13+1;
    }
    return 0;
}