/** Bismillahir Rahmanir Rahim **/
#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define endl '\n'
#define fi first
#define se second
#define ull unsigned ll
#define lld long double
#define sz(v) ((ll)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define Fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define dg(x) cerr << #x << " = " << x << endl

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    bool big_found = false;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] >= k) {
            big_found = true;
        }
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    if (sz(v) == 1) {
        cout << (v[0] == k ? "POSSIBLE" : "IMPOSSIBLE") << endl;
        return;
    }
    if (!big_found) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    ll mn_div = 1e15;
    n = sz(v);
    ll diff = v.back() - v[n - 2];
    mn_div = diff;
    for (ll i = 2; i * i <= diff; i++) {
        if (diff % i == 0) {
            mn_div = i;
            break;
        }
    }
    mn_div = min(v.front(), mn_div);
    bool all_divsible = true;
    for (ll i = 0; i < sz(v); i++) {
        all_divsible = (v[i] % mn_div == 0);
        if (!all_divsible) break;
    }
    if (!all_divsible || k % mn_div == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
int main()
{
    Fastio;
    ll tt = 1; 
    // cin >> tt;
    while (tt--) solve();

    return 0;
}