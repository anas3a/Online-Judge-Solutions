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

    ll n, k;
    cin >> n >> k;
    vll v(3e5, 0);
    ll mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v[x]++;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    for (int i = mx; i >= 0; i--)
    {
        v[i] += v[i + 1];
    }
    ll cnt = 0, ans = 0;
    for (int i = mx; i > mn; i--)
    {
        if (cnt + v[i] > k)
        {
            ans++;
            cnt = 0;
        }
        cnt += v[i];
    }
    if (cnt > 0)
        ans++;
    cout << ans << endl;
    return 0;
}
