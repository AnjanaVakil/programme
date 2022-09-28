#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool is_prime(int n)
{
    if (n <= 1)
        return false;
    int m = floor(sqrt(n) + 0.5);
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n, t, k, ask;
    cin >> n;
    vector<int> rank(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        rank[t] = i + 1;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> ask;
        printf("%04d: ", ask);
        if (rank[ask] == 0)
        {
            printf("Are you kidding?\n");
        }
        else if (rank[ask] == -1)
        {
            printf("Checked\n");
        }
        else
        {
            if (rank[ask] == 1)
            {
                printf("Mystery Award\n");
            }
            else if (is_prime(rank[ask]))
            {
                printf("Minion\n");
            }
            else
            {
                printf("Chocolate\n");
            }
            rank[ask] = -1;
        }
    }
    return 0;
}