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

bool comp(pll &a, pll &b)
{
    if (a.ff == b.ff)
    {
        return a.ss < b.ss;
    }
    return a.ff > b.ff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vpl v(n);
        for (auto &i : v)
            cin >> i.ff;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].ss;
            //sum += v[i].ss
        }
        sort(all(v), comp);
        ll x = v[0].ff;
        ll i = 0;
        while (i < n && sum + v[i].ss < x)
        {
            sum += v[i].ss;
            if (i + 1 < n)
                x = v[i + 1].ff;
            else
                x = sum;
            i++;
        }
        cout << max(sum, x) << endl;
    }
    return 0;
}
