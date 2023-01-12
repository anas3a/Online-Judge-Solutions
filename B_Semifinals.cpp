#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vpi v;
    string s1(n, '0'), s2(n, '0');
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (i < n / 2)
        {
            s1[i] = '1';
            s2[i] = '1';
        }
        v.pb(mp(a, i + 1));
        v.pb(mp(b, -(i + 1)));
    }
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        if (v[i].second > 0)
            s1[v[i].second - 1] = '1';
        else
            s2[-(v[i].second + 1)] = '1';
    }
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}
