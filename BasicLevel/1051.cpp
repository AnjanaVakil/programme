#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double r1,p1,r2,p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double a,b;
    //(a+bi)(c+di)=(ac-bd)+(bc+ad)i
    //a=r1*r2*cos(p1+p2);
	//b=r1*r2*sin(p1+p2);
    a=r1*r2*cos(p1)*cos(p2)-r1*r2*sin(p1)*sin(p2);
    b=r1*r2*cos(p1)*sin(p2)+r1*r2*sin(p1)*cos(p2);
    if(a+0.005>=0 && a<0) printf("0.00");
    else printf("%.2f",a);
    if(b>=0) printf("+%.2fi",b);
    else if(b+0.005>=0 && b<0){
        printf("+0.00i");
    }
    else printf("%.2fi",b);
    return 0;
}