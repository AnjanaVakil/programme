#include<iostream>
#include<set>
using namespace std;
int getFriendNum(int num)
{
    int sum=0;
    while(num){
        sum+=(num%10);
        num/=10;
    }
    return sum;
}
int main()
{
    int n,num;
    scanf("%d",&n);
    set<int> res;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        res.insert(getFriendNum(num));
    }
    cout << res.size() << endl;
    for(auto it=res.begin();it!=res.end();it++){
        if(it!=res.begin()) cout << " ";
        cout << *it;
    }
    return 0;
}