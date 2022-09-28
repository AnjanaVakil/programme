// #include <iostream>
// using namespace std;
// void my_swap(int *a,int *b)
// {
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// int main()
// {
//     int g1, s1, k1;
//     int g2, s2, k2;
//     char ch;
//     cin >> g1 >> ch >> s1 >> ch >> k1;
//     cin >> g2 >> ch >> s2 >> ch >> k2;
//     int g3 = g2 - g1, s3 = s2 - s1, k3 = k2 - k1;
//     if (g3 < 0 || (g3 == 0 && s3 < 0) || (g3 == 0 && s3 == 0 && k3 < 0))
//     {
//         cout << '-';
//         swap(g1, g2);
//         my_swap(&s1, &s2);
//         my_swap(&k1, &k2);
//     }
//     g3 = g2 - g1, s3 = s2 - s1, k3 = k2 - k1;
//     while (k3 < 0)
//     {
//         if (s3 > 0)
//         {
//             k3 = k3 + 29;
//             s3--;
//         }
//     }
//     while (s3 < 0)
//     {
//         if (g3 > 0)
//         {
//             s3 = s3 + 17;
//             g3--;
//         }
//     }
//     cout << g3 << '.' << s3 << '.' << k3;
// }
#include <iostream>
using namespace std;
int main()
{
    int Galleon, Sickle, Knut;
    int Galleon1, Sickle1, Knut1;
    char ch;
    cin >> Galleon >> ch >> Sickle >> ch >> Knut;
    cin >> Galleon1 >> ch >> Sickle1 >> ch >> Knut1;
    int P = Galleon * 29 * 17 + Sickle * 29 + Knut;
    int A = Galleon1 * 29 * 17 + Sickle1 * 29 + Knut1;
    int money = P - A;
    if (money > 0)
        cout << "-" << money / 17 / 29 << "." << money % (17 * 29) / 29 << "." << money % 29;
    else
        cout << -money / 17 / 29 << "." << -money % (17 * 29) / 29 << "." << -money % 29;
    return 0;
}
