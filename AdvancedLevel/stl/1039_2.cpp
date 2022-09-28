#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//hash散列
int hashFunc(string name)
{
    int id=0;
    for(int i=0;i<3;i++){
        id=id*26+(name[i]-'A');
    }
    id=id*10+(name[3]-'0');
    return id;
}
const int maxn=26*26*26*10+10;
vector<int> v[maxn];
int main()
{
    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int index,snum;
        cin >> index >> snum;
        for(int j=0;j<snum;j++){
            string name;
            cin >> name;
            v[hashFunc(name)].push_back(index);
        }
    }
    for(int i=0;i<n;i++){
        string query;
        cin >> query;
        cout << query << " ";
        int id=hashFunc(query);
        int cnt=v[id].size();
        cout << cnt;
        if(cnt!=0){
            sort(v[id].begin(),v[id].end());
            for(int j=0;j<cnt;j++){
                cout << " ";
                cout << v[id][j];
            }
        }
        cout << "\n";
    }
    return 0;
}