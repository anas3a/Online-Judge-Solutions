#include <bits/stdc++.h>

using namespace std;
long long n;
long long f(long long x, int i)
{
    long long a = 1e12, b = 1e12;
    if (x == n)
        return 0;
    if (x > n)
    {
        a = 1 + f(x - 1, i + 1);
    }
    else
    {
        a = 1 + (x + i, i + 1);
        b = 1 + (x - 1, i + 1);
    }
    return min(a, b);
}
int main()
{

    long long t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        n = x;
        cout << f(0, 1) << endl;
    }
    return 0;
}
