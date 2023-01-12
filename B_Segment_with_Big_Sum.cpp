#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, s;
    cin >> n >> s;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    ll sum = 0, ans = INT_MAX;
    for (int i = 0, l = 0; i < n; i++)
    {
        sum += v[i];
        while (sum - v[l] >= s)
            sum -= v[l++];
        if (sum >= s)
            ans = min(ans, (ll)i - l + 1);
    }
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
    return 0;
}
