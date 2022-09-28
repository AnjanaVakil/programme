#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int fullscore[100];
    int choice,right;
    vector<vector<char> > v;
    for(int i=1;i<=m;i++){
        cin >> fullscore[i] >> choice >> right;
        char c;
        for(int j=1;j<=right;j++){
            cin >> c;
            v[i].push_back(c);
        }
    }
    int wrong[100]={0};
    for(int i=1;i<=n;i++){
        int score=0;
        scanf("\n");
        for(int j=1;j<=m;j++){
            if(j!=1) scanf(" ");
            int flag=1;
            int choose;
            char t;
            scanf("(%d",&choose);
            int k;
            for(k=1;k<=choose;k++){
                scanf(" %c",&t);
                if(t!=v[j][k]){
                    // wrong[j]+=1;
                    flag=0;
                }
            }
            scanf(")");
            if(flag==1){
                score+=fullscore[j];
            }
        }
        cout << score << endl;
    }
    return 0;
}