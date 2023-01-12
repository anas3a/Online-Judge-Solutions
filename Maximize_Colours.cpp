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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll cnt = 0;
        vll v;
        v.pb(a);
        v.pb(b);
        v.pb(c);
        sort(rall(v));
        if (v[0])
        {
            cnt++, v[0]--;
        }
        if (v[1])
        {
            cnt++, v[1]--;
        }
        if (v[2])
        {
            cnt++, v[2]--;
        }
        if (v[0] && v[2])
        {
            cnt++;
            v[0]--, v[2]--;
        }
        if (v[0] && v[1])
        {
            cnt++;
            v[0]--, v[1]--;
        }
        if (v[1] && v[2])
        {
            cnt++;
            v[1]--, v[2]--;
        }
        cout << cnt << endl;
    }
    return 0;
}