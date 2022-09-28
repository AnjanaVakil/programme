#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    int N;
    cin >> N;
    string s;
    //flag和temp在哪里初始化值得关注下
    int flag,temp=1;
    int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int m[] = {1, 0, 40, 9, 8, 7, 6, 5, 4, 3, 2};
    for (int i = 0; i < N; i++)
    {
        flag = 1;
        cin >> s;
        int z = 0;
        for (int i = 0; i < 17; i++)
        {
            if (isdigit(s[i]))
            {
                z += (s[i] - '0') * weight[i];
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            z %= 11;
            if ((s[17] - '0') != m[z])
            {
                cout << s << endl;
                temp=0;
            }
        }
        else
        {
            cout << s << endl;
            temp=0;
        }
    }
    if(temp==1){
        cout << "All passed";
    }
    return 0;
}