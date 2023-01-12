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

    ll n;
    cin >> n;
    vi v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == '-' || sz(s) > 7)
            continue;
        ll x = stoi(s);
        v.pb(x);
    }
    sort(all(v));
    for (int i = 0; i < sz(v); i++)
    {
        if (i != v[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << sz(v) << endl;
    return 0;
}
