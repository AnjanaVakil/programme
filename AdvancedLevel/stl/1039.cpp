#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//13:35-14:10 35min 也太慢了 25score
int main()
{
    int n,k;
    cin >> n >> k;
    map<string,vector<int> > stu;
    for(int i=0;i<k;i++){
        int index,snum;
        cin >> index >> snum;
        for(int j=0;j<snum;j++){
            string name;
            cin >> name;
            stu[name].push_back(index);
        }
    }
    for(int i=0;i<n;i++){
        string query;
        cin >> query;
        cout << query << " ";
        int cnt=stu[query].size();
        cout << cnt;
        sort(stu[query].begin(),stu[query].end());
        for(int j=0;j<cnt;j++){
            cout << " ";
            cout << stu[query][j];
        }
        cout << "\n";
    }
    return 0;
}