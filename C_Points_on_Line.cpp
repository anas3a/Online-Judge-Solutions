#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, d, ans = 0;
    cin >> n >> d;
    vll v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 0, j = 0; i < n - 2; i++)
    {
        while (j < n && abs(v[j] - v[i]) <= d)
        {
            j++;
        }
        ll x = j - i - 2;
        if (x >= 1)
            ans += (x * (x + 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}
