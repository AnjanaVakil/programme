#include<iostream>
using namespace std;
struct student{
    string name;
    int id[2500];
    int sum;
};
int main()
{
   int n,k,id,cnt;
   cin >> n >> k;
   string s;
   student stu[40000];
   for(int i=0;i<n;i++){
       cin >> id >> cnt;
       for(int j=0;j<cnt;j++){
           cin >> s;
       }
   }
}