//13-25 20'
#include<iostream>
#include<map>
using namespace std;
//2^24 20-6 2^4=16-1 10^7
int main()
{
    int m,n;
    cin >> m >> n;
    map<int,int> mapp;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> temp;
            mapp[temp]++;
        }
    }
    int domin,dominCnt=-1;
    for(map<int,int>::iterator it=mapp.begin();it!=mapp.end();it++){
        if(it->second > dominCnt){
            domin=it->first;
            dominCnt=it->second;
        }
    }
    cout << domin;
    return 0;
}