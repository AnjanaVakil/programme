#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct node{
    int pro;
    vector<int> rea;
};
map<int,vector<node> > mp;
vector<int> v;
int main()
{
    int n,m,k;
    cin >> n;
    vector<int> rea(n);
    for(int i=0;i<n;i++){
        cin >> rea[i];
    }
    cin >> m;
    vector<int> pro(m);
    for(int i=0;i<m;i++){
        cin >> pro[i];
    }
    cin >> k;
    getchar();
    string s;
    // Note that each reactant can be used only once.
    //The equations must be print in the same order as the products given in the input.
    for(int i=0;i<k;i++){
        string s;
        vector<int> in;
        while(1){
            cin >> s;
            if(s=="->"){
                cin >> s;
                int id=stoi(s);
                mp[id].push_back(node{id,in});
                break;
            }
            if(s!="+"){
                in.push_back(stoi(s));
            }
        }
    }
    return 0;
}