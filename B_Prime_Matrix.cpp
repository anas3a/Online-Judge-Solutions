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

    ll n, m, x = 1e6 + 100;
    cin >> n >> m;
    vector<bool> prime(x, true);
    prime[0] = prime[1] = false;
    set<int> s;
    for (ll i = 2; i < x; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j < x; j += i)
                prime[j] = false;
            s.insert(i);
        }
    }
    vvi v(n, vi(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll z;
            cin >> z;
            auto it = s.lower_bound(z);
            v[i][j] = abs(*it - z);
        }
    }
    ll ans = 1e15;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        for (int j = 0; j < m; j++)
            sum += v[i][j];
        ans = min(ans, sum);
    }
    for (int i = 0; i < m; i++)
    {
        ll sum = 0;
        for (int j = 0; j < n; j++)
            sum += v[j][i];
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
