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
    multiset<ll> s;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        s.insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        ll a;
        cin >> a;
        auto it = s.upper_bound(a);
        if (it == s.begin())
            cout << -1 << endl;
        else
        {
            cout << *(--it) << endl;
            s.erase(it);
        }
    }
    return 0;
}
