#include<iostream>
using namespace std;
string minWindow(string s, string t)
{
    int lens = s.length(), lent = t.length();
    while (lent < lens)
    {
        for (int i = 0; i < lens; i++)
        {
            string str = s.substr(i, lent);
            cout << str << "++" << endl;
            int j;
            for (j = 0; j < lent; j++)
            {
                if (str.find(t[j]) == string::npos)
                    break;
            }
            if (j == lent-1)
                return str;
        }
        lent += 1;
    }
    return "";
}
int main()
{
    string s,t;
    freopen("input.txt","r",stdin);
    cin >> s >> t;
    cout << minWindow(s,t) << endl;
}