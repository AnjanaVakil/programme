#include <iostream>
using namespace std;
//部分正确
int main()
{
    int n;
    char c;
    cin >> n >> c;
    //1 3*2 5*2 17 7*2
    int print = 1;
    int row = 1;
    int remain = n - print;
    while (print <= n && remain > row * 2)
    {
        row += 2;
        print += (row * 2);
        remain = n - print;
    }
    for (int i = 0; i < row / 2; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < row - i * 2; j++)
        {
            cout << c;
        }
        cout << "\n";
    }
    for (int i = 0; i < row / 2 + 1; i++)
    {
        for (int j = row / 2; j > i; j--)
        {
            cout << " ";
        }
        for (int j = i * 2 + 1; j > 0; j--)
        {
            cout << c;
        }
        cout << "\n";
    }
    cout << remain << endl;
    return 0;
}