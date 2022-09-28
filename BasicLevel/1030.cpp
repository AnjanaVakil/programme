#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int N;
    //p（≤10^9）
    //每个数不超过 10^9
    //相乘的结果才可能会溢出int
    long long p;
    cin >> N >> p;
    int num[100000];
    for(int i=0;i<N;i++){
        cin >> num[i];
    }
    int res[]={0};
    for(int i=0;i<N;i++){
        int max=num[i],min=num[i];
        for(int j=0;j<N && j!=i;j++){
            int temp=min*p;
            if(num[j]>max && num[j]<=temp){
                res[i]+=1;
                max=num[j];
            }
            if(num[j]<min){
                min=num[j];
                if(max<min*p){
                    res[i]+=1;
                }
            }
        }
    }
    sort(res,res+N);
    cout << res[N-1];
    return 0;
}