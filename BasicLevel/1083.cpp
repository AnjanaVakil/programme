#include<iostream>
using namespace std;
int main()
{
    int n,num,t;
    cin >> n;
    int diff[10000+5]={0};
    //8
    // 3 5 8 6 2 1 4 7
    // 2 3 5 2 3 5 3 1
    for(int i=0;i<n;i++){
        cin >> num;
        diff[abs(num-(i+1))]++;
        // if(num>(i+1)){
        //     t=num-(i+1);
        //     diff[t]+=1;
        // }else{
        //     t=(i+1)-num;
        //     diff[t]+=1;
        // }
    }
    //边界条件要多注意
    for(int i=10000;i>=0;i--){
        if(diff[i]>1){
            cout << i << " " << diff[i] << endl;
        }
    }
    return 0;
}