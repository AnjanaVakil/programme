#include<iostream>
#include<cmath>
using namespace std;
//16:00-16 12' 23 15‘ 30 25‘
bool isPrime(int num)
{
    //1既不是质数，也不是合数
    //不要忘记1的判断
    int sqr=(int)sqrt(num*1.0);
    //注意，这边是<=,否则有错！
    for(int i=2;i<=sqr;i++){
        if(num%i==0) return false;
    }
    return true;
}
int main()
{
    int tsize,n;
    //如果只是hashTable[10005]，会过不了后面两个数据
    int hash[10010]={0};
    cin >> tsize >> n;
    while(isPrime(tsize)==false){
        tsize++;
    }
    int key;
    for(int i=0;i<n;i++){
        cin >> key;
        int index=key%tsize;
        if(hash[index]==0){
            if(i!=0) cout << " ";
            cout << index;
            hash[index]=1;
        }else{
            //Quadratic probing (with positive increments only) is used to solve the collisions.
            int step;
            for(step=1;step<=tsize-1;step++){
                index=(key+step*step)%tsize;
                if(hash[index]==0){
                    if(i!=0) cout << " ";
                    cout << index;  
                    hash[index]=1;
                    break;
                }
            }
            if(step>=tsize){
                if(i!=0) cout << " ";
                cout << "-";
            }
        }
    }
    return 0;
}