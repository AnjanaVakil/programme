#include <iostream>
using namespace std;
int main()
{
    int T, K;
    cin >> T >> K;
    int n1, b, t, n2;
    for (int i = 0; i < K; i++)
    {
        cin >> n1 >> b >> t >> n2;
        int ans = n1 > n2 ? 0 : 1;
        if (T == 0) {
            printf("Game Over.\n");
            return 0;
        } else if (t > T) {
            printf("Not enough tokens.  Total = %d.\n", T);
        } else if (ans == b) {
            T += t;
            printf("Win %d!  Total = %d.\n", t, T);
        } else if (ans != b) {
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
        } 
    }
    return 0;
}