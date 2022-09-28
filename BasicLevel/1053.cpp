#include<iostream>
using namespace std;
int main()
{
    int n,d,k;
    double e,ei;
    cin >> n >> e >> d;
    int maybe=0,must=0;
    for(int i=0;i<n;i++){
        cin >> k;
        int day=0;
        for(int j=0;j<k;j++){
            cin >> ei;
            if(ei<e){
                day+=1;
            }
        }
        if(day>(k/2)){
            // if(k>d){
            //     must++;
            // }else{
            //     maybe++;
            // }
            //更好的写法
            k>d?must++:maybe++;
        }
    }
    // printf("%.1f",maybe*1.0/n*100);
    // cout << "% ";
    // printf("%.1f",must*1.0/n*100);
    // cout << "%";
    //printf中要使用两个百分号%%表示输出一个百分号
    printf("%.1f%% %.1f%%",(double)maybe/n*100,(double)must/n*100);
    return 0;
}