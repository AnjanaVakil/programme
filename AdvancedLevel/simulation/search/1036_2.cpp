#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string female,male;
    int femalescore=-1,malescore=101;
    for(int i=0;i<n;i++){
        string name,sex,num;
        int score;
        cin >> name >> sex >> num >> score;
        if(sex=="F"){
            if(score>femalescore){
                femalescore=score;
                female=name+" "+num;
            }
        }else{
            if(score<malescore){
                malescore=score;
                male=name+" "+num;
            }
        }
    }
    if(femalescore==-1) cout << "Absent\n";
    else cout << female << endl;
    if(malescore==101) cout << "Absent\n";
    else cout << male << endl;
    if(femalescore!=-1 && malescore!=101){
        cout << abs(femalescore-malescore) << endl;
    }else{
        cout << "NA\n";
    }
    return 0;
}