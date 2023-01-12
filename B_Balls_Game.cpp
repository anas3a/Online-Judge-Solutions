#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

    ll n, k, x;
    cin >> n >> k >> x;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] == x && v[i] == v[i + 1])
        {
            ll p = i, q = i + 1, cnt = 0;
            bool f = true;
            while (true)
            {
                ll c1 = 1, c2 = 1;
                while (p > 0 && v[p] == v[p - 1])
                    p--, c1++;
                while (q < n - 1 && v[q] == v[q + 1])
                    q++, c2++;
                if (c1 + c2 < 3 && !f)
                    break;
                cnt = q - p + 1;
                p = max(p - 1, 0ll);
                q = min(q + 1, n - 1);
                if (v[p] != v[q])
                    break;
                if (p == 0 && q == n - 1)
                    break;
                f = false;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
