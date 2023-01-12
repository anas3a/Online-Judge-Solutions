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

bool comp(pll &a, pll &b)
{
    if (a.ss == b.ss)
        return a.ff > b.ff;
    return a.ss < b.ss;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vll v(1003, 0);
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j += i)
            v[j]++;
    }
    vpl vx;
    for (int i = 1; i <= 1000; i++)
        vx.pb({i, v[i]});
    sort(all(vx), comp);
    
    ll t, cs = 0;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << "Case " << ++cs << ": " << vx[n - 1].ff << endl;
    }
    return 0;
}