#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct person{
    // char id[15];
    string id;
    int signin[3],signout[3];
};
bool signincmp(person a,person b)
{
    if(a.signin[0]!=b.signin[0])
        return a.signin[0]<b.signin[0];
    if(a.signin[1]!=b.signin[1])
        return a.signin[1]<b.signin[1];
    return a.signin[2]<b.signin[2];
}
bool signoutcmp(person a,person b)
{
    if(a.signout[0]!=b.signout[0])
        return a.signout[0]>b.signout[0];
    if(a.signout[1]!=b.signout[1])
        return a.signout[1]>b.signin[1];
    return a.signout[2]>b.signout[2];
}
int main()
{
    int m;
    scanf("%d",&m);
    vector<person> per(m);
    for(int i=0;i<m;i++){
        cin >> per[i].id;
        scanf("%d:%d:%d %d:%d:%d",&per[i].signin[0],&per[i].signin[1],&per[i].signin[2],&per[i].signout[0],&per[i].signout[1],&per[i].signout[2]);
    }
    sort(per.begin(),per.end(),signincmp);
    cout << per[0].id << " ";
    sort(per.begin(),per.end(),signoutcmp);
    cout << per[0].id;
}