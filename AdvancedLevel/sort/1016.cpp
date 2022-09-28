#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
//12:30-13:50 18:40-19:20 18'
using namespace std;
vector<int> rate(26);
struct record{
    int month,day,hour,minute;
    string tag;
};
struct customer{
    vector<record> recodes;
};
bool cmp(record a,record b)
{
    if(a.day!=b.day) return a.day<b.day;
    if(a.hour!=b.hour) return a.hour<b.hour;
    if(a.minute!=b.minute) return a.minute<b.minute;
    if(a.tag!=b.tag) return a.tag>b.tag;
}
int cntTime(record r){
    return r.day*24*60+r.hour*60+r.minute;
}
double billFromZero(record r){
    double total=rate[24]*60*r.day;
    for(int i=0;i<r.hour;i++){
        total+=rate[i]*60;
    }
    total+=rate[r.hour]*r.minute;
    return total/100.0;
}
// int cntDiff(record a,record b){
//     int d=(b.day-a.day)*24*60;
//     int h=(b.hour-a.hour)*60;
//     int m=(b.minute-a.minute);
//     return d+h+m;
// }
// double cntCharge(record a,record b){
//     double c=0;
//     while(a.day<b.day || a.hour<b.hour || a.minute<b.minute){
//         c+=rate[a.hour];
//         if(a.minute==60){
//             a.minute=0;
//             a.hour++;
//         }
//         if(a.hour==24){
//             a.hour=0;
//             a.day++;
//         }
//     }
//     return c;
// }
int main()
{
    for(int i=0;i<24;i++){
        cin >> rate[i];
        rate[24]+=rate[i];
    }
    int n;
    cin >> n;
    string name,tag;
    int month,day,hour,minute;
    map<string,customer> cus;
    for(int i=0;i<n;i++){
        record rec;
        cin >> name;
        scanf("%d:%d:%d:%d",&rec.month,&rec.day,&rec.hour,&rec.minute);
        cin >> rec.tag;
        cus[name].recodes.push_back(rec);
    }
    for(map<string,customer>::iterator it=cus.begin();it!=cus.end();it++){
        cout << it->first << " ";
        vector<record> re=it->second.recodes;
        printf("%02d\n",re[0].month);
        sort(re.begin(),re.end(),cmp);
        double charge,amount=0.0;
        int diff;
        for(int i=0;i<re.size()-1;i++){
            if(re[i].tag=="on-line" && re[i+1].tag=="off-line"){
                printf("%02d:%02d:%02d %02d:%02d:%02d ",re[i].day,re[i].hour,re[i].minute,re[i+1].day,re[i+1].hour,re[i+1].minute);
                diff=cntTime(re[i+1])-cntTime(re[i]);
                charge=billFromZero(re[i+1])-billFromZero(re[i]);
                printf("%d $%.2f\n",diff,charge);
                amount+=charge;
            }
        }
        printf("Total amount: $%.2f\n",amount);
    }
    return 0;
}