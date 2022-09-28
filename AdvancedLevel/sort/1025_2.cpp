#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct testee{
    string id;
    int location,score,local_rank,final_rank;
};
bool cmp(testee a,testee b)
{
    return a.score!=b.score?a.score>b.score:a.id<b.id;
}
int main()
{
    int n;
    cin >> n;
    vector<testee> fin;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        vector<testee> v(k);
        for(int j=0;j<k;j++){
            cin >> v[j].id >> v[j].score;
            v[j].location=i+1;
        }
        sort(v.begin(),v.end(),cmp);
        v[0].local_rank=1;
        fin.push_back(v[0]);
        for(int j=1;j<k;j++){
            v[j].local_rank=j+1;
            if(v[j].score==v[j-1].score){
                v[j].local_rank=v[j-1].local_rank;
            }
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(),fin.end(),cmp);
    fin[0].final_rank=1;
    for(int i=1;i<fin.size();i++){
        fin[i].final_rank=i+1;
        if(fin[i].score==fin[i-1].score){
            fin[i].final_rank=fin[i-1].final_rank;
        }
    }
    cout << fin.size() << "\n";
    for(int i=0;i<fin.size();i++){
        cout << fin[i].id << " " << fin[i].final_rank << " " << fin[i].location << " " << fin[i].local_rank << "\n";
    }
    return 0;
}