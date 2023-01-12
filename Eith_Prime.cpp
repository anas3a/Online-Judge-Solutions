#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10000000;
    vector<bool> p(n + 3, true);
    vector<int> ans;
    p[0] = p[1] = false;
    for (long long i = 2; i <= n; i++)
    {
        if (p[i])
        {
            if (p[i - 2])
                ans.push_back(i);
            for (long long j = i * i; j <= n; j += i)
                p[j] = false;
        }
    }
    int x;
    while(cin >> x)
    {
        cout << ans[x - 1] << endl;
    }
    return 0;
}
