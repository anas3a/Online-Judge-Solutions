#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k, s;
    cin >> k >> s;
    long long ans = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            long long sum = i + j;
            if (sum <= s && (s - sum) <= k)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
