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

    ll n, q;
    cin >> n >> q;
    vll v(n), vx(n + 1, 0);
    for (auto &i : v)
        cin >> i;
    vll vl(n + 1, 0), vr(n + 1, 0);
    for (int i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        vl[a]++, vr[b]++;
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += vl[i];
        vx[i] = cnt;
        cnt -= vr[i];
    }
    sort(rall(v));
    sort(rall(vx));
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += v[i] * vx[i];
    cout << ans << endl;
    return 0;
}
