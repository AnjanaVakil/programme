#include<iostream>
#include<map>
#include<cctype>
//注意这里的头文件是cctype
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    map<string,int> count;
    int i=0;
    while(i<s.length()){
        string word;
        //isalpha(s[i]) || isdigit(s[i])可以使用cctype的isalnum()
        while(i<s.length() && (isalpha(s[i]) || isdigit(s[i]))){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=tolower(s[i]);
            }
            word+=s[i];
            i++;
        }
        if(word!=""){
            count[word]++;
            // cout << word << endl;
        }
        while(i<s.length() && !(isalpha(s[i]) || isdigit(s[i]))){
            i++;
        }
    }
    int maxcnt=-1;
    string res;
    for(map<string,int>::iterator it=count.begin();it!=count.end();it++){
        if(it->second>maxcnt){
            res=it->first;
            maxcnt=it->second;
        }
    }
    cout << res << " " << maxcnt;
    return 0;
}