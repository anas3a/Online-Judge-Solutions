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

string t, p;
vi v;
int n;

bool f(ll x)
{
    string s = t;
    for (int i = 0; i < x; i++)
    {
        s[v[i] - 1] = 'Z';
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == p[j])
            j++;
    }
    return j >= sz(p);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t >> p;
    n = sz(t);
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    ll l = 0, r = n;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (f(m))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    return 0;
}
