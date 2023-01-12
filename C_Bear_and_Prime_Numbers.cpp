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

int nx = 1e7 + 1;
vector<bool> p(nx, true);
vi v(nx, 0), m(nx, 0);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    p[0] = p[1] = false;
    for (ll i = 2; i < nx; i++)
    {
        if (p[i])
        {
            ll cnt = m[i];
            for (int j = i + i; j < nx; j += i)
            {
                p[j] = false;
                cnt += m[j];
            }
            v[i] = cnt;
        }
    }
    for (int i = 1; i < nx; i++)
        v[i] += v[i - 1];
    ll q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l = min(l, nx - 1);
        r = min(r, nx - 1);
        cout << v[r] - v[l - 1] << endl;
    }
    return 0;
}
