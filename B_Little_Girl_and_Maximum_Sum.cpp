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

    ll n, m;
    cin >> n >> m;
    vll v(n);
    for (auto &i : v)
        cin >> i;
    sort(rall(v));
    vll vx(n + 1, 0), vy(n + 1, 0);
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        vx[a]++;
        vy[b]++;
    }
    ll cnt = 0;
    vll vk;
    for (int i = 1; i <= n; i++)
    {
        cnt += vx[i];
        cnt -= vy[i - 1];
        vk.pb(cnt);
    }
    sort(rall(vk));
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += vk[i] * v[i];
    }
    cout << sum << endl;
    return 0;
}