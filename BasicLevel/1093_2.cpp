#include<iostream>
using namespace std;
int book[100];
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<a.length();i++){
        book[a[i]]++;
    }
    for(int i=0;i<b.length();i++){
        book[b[i]]++;
    }
    for(int i=0;i<a.length();i++){
        if(book[a[i]]!=0){
            cout << a[i];
            book[a[i]]=0;
        }
    }
    for(int i=0;i<b.length();i++){
        if(book[b[i]]!=0){
            cout << b[i];
            book[b[i]]=0;
        }
    }
}