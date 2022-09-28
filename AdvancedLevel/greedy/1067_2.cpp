#include<iostream>
#include<algorithm>
using namespace std;
//5 4 0 2 1 3
//0 4 2 1 3
//0 1 2 4 3
//0 1 2 3 4
int main()
{
    int n;
    cin >> n;
    int hashpos[100005];
    int num;
    int left=n-1; //left存放除0以外不在本位上的数的个数
    for(int i=0;i<n;i++){
        cin >> num;
        //记录num的下标
        hashpos[num]=i;
        if(num!=0 && num==i){
            left--;
        }
    }
    int cnt=0;
    int k=1;
    while(left>0){
        if(hashpos[0]==0){
            while(k<n){
                if(hashpos[k]!=k){
                    swap(hashpos[0],hashpos[k]);
                    cnt++;
                    break;
                }
                k+=1;
            }
        }
        while(hashpos[0]!=0){
            swap(hashpos[0],hashpos[hashpos[0]]);
            cnt++;
            left--;
        }
    }
    cout << cnt;
    return 0;
}