#include<iostream>
using namespace std;
struct student{
    string s;
    int a,b;
};
int main()
{
    int N,M,a;
    cin >> N;
    student stu[1000];
    for(int i=0;i<N;i++){
        cin >> stu[i].s >> stu[i].a >> stu[i].b;
    }
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> a;
        for(int i=0;i<N;i++){
            if(stu[i].a==a){
                cout << stu[i].s << " " << stu[i].b << "\n";
            }
        }
    }
}