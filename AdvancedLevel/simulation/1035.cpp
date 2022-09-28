#include<iostream>
#include<vector>
using namespace std;
//14:50-15:10 5' 15:15 20'
int main()
{
    int n;
    cin >> n;
    string name,pass;
    vector<string> v;
    for(int i=0;i<n;i++){
        cin >> name >> pass;
        int flag=0;
        for(int i=0;i<pass.length();i++){
            switch(pass[i]){
                case '1':{
                    pass[i]='@';
                    flag=1;
                    break;
                }
                case '0':{
                    pass[i]='%';
                    flag=1;
                    break;
                }
                case 'l':{
                    pass[i]='L';
                    flag=1;
                    break;
                }
                case 'O':{
                    pass[i]='o';
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            //还要输出修改后的总个数，可以保存在字符串数组vector中
            string temp=name+" "+pass;
            v.push_back(temp);
        }
    }
    int cnt=v.size();
    if(v.size()!=0){
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++){
            cout << v[i] << endl;
        }
    }else if(n==1){
        printf("There is 1 account and no account is modified");
    }else{
        printf("There are %d accounts and no account is modified",n);
    }
    return 0;
}