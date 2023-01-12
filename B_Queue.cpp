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

    ll n;
    cin >> n;
    map<int, int> m;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        m[a] = b;
        s.insert(b);
    }
    vi v(n + 1);
    ll x = 0;
    for (int i = 2; i <= n; i += 2)
    {
        if (m[x] == 0)
            break;
        v[i] = m[x];
        x = v[i];
    }
    for (auto &i : m)
    {
        if (s.find(i.ff) == s.end())
        {
            x = i.ff;
            break;
        }
    }
    v[1] = x;
    for (int i = 3; i <= n; i += 2)
    {
        if (m[x] == 0)
            break;
        v[i] = m[x];
        x = v[i];
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
