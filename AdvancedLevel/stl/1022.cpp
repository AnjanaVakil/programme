//26-05 30'
#include<iostream>
#include<map>
#include<set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string,set<string> > mapp;
    string id,title,author,pub,key,year;
    for(int i=0;i<n;i++){
        cin >> id;
        //这里不要忘记加getchar()!!!
        getchar();
        getline(cin,title); 
        getline(cin,author);
        mapp[title].insert(id);
        mapp[author].insert(id);
        //关键字的处理！
        while(cin >> key){
            mapp[key].insert(id);
            if(getchar()=='\n') break;
        }
        getline(cin,pub);
        getline(cin,year);
        mapp[pub].insert(id);
        mapp[year].insert(id);
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int j;
        string query;
        scanf("%d: ",&j);
        getline(cin,query);
        cout << j << ": " << query << "\n";
        if(!mapp[query].empty()){
            for(set<string>::iterator it=mapp[query].begin();it!=mapp[query].end();it++){
                cout << *it << "\n";
            }
        }
        else{
            cout << "Not Found\n";
        }
    }
    return 0;
}