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

    string s;
    cin >> s;
    ll a, b;
    cin >> a >> b;
    vi va, vb;
    ll x = 0;
    for (int i = 0; i < sz(s); i++)
    {
        x = ((x * 10) + s[i] - '0') % a;
        if (x == 0 && i < sz(s) - 1 && s[i + 1] != '0')
            va.pb(i);
    }
    x = 0;
    ll y = 1;
    ll z = log10(b) + 1;
    for (int i = 0; i < z; i++)
        y *= 10;
    for (int i = sz(s) - z; i < sz(s); i++)
    {
        x *= 10;
        x = x + s[i] - '0';
    }
    if (x != 0)
    {
        x %= b;
        if (!x)
            vb.pb(sz(s) - z);
    }
    for (int i = sz(s) - z - 1; i > 0; i--)
    {
        x = (x + ((s[i] - '0') * y)) % b;
        if (x == 0 && s[i] != '0')
            vb.pb(i);
    }
    sort(all(vb));
    ll aa = -1, bb = -1;
    for (auto &i : va)
    {
        if (binary_search(all(vb), i + 1))
        {
            aa = i, bb = i + 1;
            break;
        }
    }
    if (aa == -1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i <= aa; i++)
            cout << s[i];
        cout << endl;
        for (int i = bb; i < sz(s); i++)
            cout << s[i];
        cout << endl;
    }
    for (auto &i : vb)
        cout << i << endl;
    return 0;
}