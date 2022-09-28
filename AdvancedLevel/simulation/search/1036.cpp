#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//16:30-45 15min 25'
struct student{
    string name,gender,id;
    int grade;
};
int main()
{
    int n;
    cin >> n;
    vector<student> stu(n+1);
    int fhigh=INT_MIN,mlow=INT_MAX;
    int ftag=-1,mtag=-1;
    for(int i=0;i<n;i++){
        cin >> stu[i].name >> stu[i].gender >> stu[i].id >> stu[i].grade;
        if(stu[i].gender=="F"){
            if(stu[i].grade>fhigh){
                fhigh=stu[i].grade;
                ftag=i;
            }
        }else{
            if(stu[i].grade<mlow){
                mlow=stu[i].grade;
                mtag=i;
            }
        }
    }
    int flag=true;
    if(ftag!=-1){
        cout << stu[ftag].name << " " << stu[ftag].id << endl;
    }else{
        flag=false;
        cout << "Absent\n";
    }
    if(mtag!=-1){
        cout << stu[mtag].name << " " << stu[mtag].id << endl;
    }else{
        flag=false;
        cout << "Absent\n";
    }
    if(flag){
        cout << abs(stu[ftag].grade-stu[mtag].grade) << endl;
    }else{
        cout << "NA\n";
    }
    return 0;
}