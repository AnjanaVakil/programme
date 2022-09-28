#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1117 20:00-18 9'
int main() 
{
    int n;
    cin >> n;
    vector<int> dis(n);
    for(int i=0;i<n;i++){
        cin >> dis[i];
    }
    sort(dis.begin(),dis.end());
    int e=n,cnt=0;
    int i=dis.size()-1;
    while(i>=0){
        if(dis[i]>e){
            cnt++;
        }else{
            if(cnt>=e){
                break;
            }else{
                i=dis.size()-1;
                e--;
            }
        }
        i--;
    }
    cout << e << endl;
    //6: 7 9 10 8 7 8
    return 0;
}