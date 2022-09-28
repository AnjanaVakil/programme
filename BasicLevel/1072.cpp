#include<iostream>
using namespace std;
struct student{
    string name;
    int k;
    string thing[11];
};
int main()
{
    int n,m;
    cin >> n >> m;
    string ban[7];
    student stu[1000];
    for(int i=0;i<m;i++){
        cin >> ban[i];
    }
    for(int i=0;i<n;i++){
        cin >> stu[i].name >> stu[i].k;
        for(int j=0;j<stu[i].k;j++){
            cin >> stu[i].thing[j];
        }
    }
    int cnts=0,cntt=0;
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<stu[i].k;j++){
            for(int t=0;t<m;t++){
                if(stu[i].thing[j]==ban[t]){
                    if(flag==0){
                        cout << stu[i].name << ":";
                        cnts++;
                    }
                    cout << " " << ban[t];
                    cntt++;
                    flag=1;
                }
            }
        }
        if(flag){
            cout << "\n";
        }
    }
    cout << cnts << " " << cntt; 
    return 0;
}