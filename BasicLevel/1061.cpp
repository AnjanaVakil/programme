#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int fullscore[100],right[100];
    for(int i=0;i<m;i++){
        cin >> fullscore[i];
    }
    for(int i=0;i<m;i++){
        cin >> right[i];
    }
    for(int i=0;i<n;i++){
        int res=0;
        int answer;
        for(int j=0;j<m;j++){
            cin >> answer;
            if(answer==right[j]){
                res+=fullscore[j];
            }
        }
        cout << res << endl;
    }
    return 0;
}