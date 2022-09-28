#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int max=0,min=100;
    string max_name,max_id,min_name,min_id;
    while(n--){
        string name,id;
        int grade;
        cin >> name >> id >> grade;
        if(grade>max){
            max_name=name;
            max_id=id;
            max=grade;
        }
        if(grade<min){
            min_name=name;
            min_id=id;
            min=grade;
        }
    }
    cout << max_name << " " << max_id << endl;
    cout << min_name << " " << min_id << endl;
    return 0;
}