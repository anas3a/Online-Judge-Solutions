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
    vll va(n), vb(m);
    for (auto &i : va)
        cin >> i;
    for (auto &i : vb)
        cin >> i;
    sort(all(va));
    ll gx;
    if (n == 1)
        gx = va[0];
    else
        gx = va[1] - va[0];
    for (int i = 2; i < n; i++)
    {
        gx = __gcd(gx, va[i] - va[0]);
    }
    for (int i = 0; i < m; i++)
    {
        ll x;
        if (n == 1)
            x = vb[i] + va[0];
        else
            x = __gcd(va[0] + vb[i], gx);
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
