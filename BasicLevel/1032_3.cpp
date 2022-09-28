#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    int a[100005]={0};
    cin >> n;
    int max=INT_MIN,max_id;
    for(int i=0;i<n;i++){
        int id,score;
        cin >> id >> score;
        a[id]+=score;
        if(a[id]>max){
            max=a[id];
            max_id=id;
        }
    }
    cout << max_id << " " << max;
    return 0;
}