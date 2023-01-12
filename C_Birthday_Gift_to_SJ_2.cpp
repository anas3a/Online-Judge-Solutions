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

const ll N = 1e18 + 100;
vector<ll> v;
ll tt, a, b;

void precal()
{
    ll a = 1, b = 1;
    int cnt = 0;
    while (1)
    {
        ll k = a + b;
        v.pb(k);
        a = b;
        b = k;
        cnt++;
        if (k > N || k < 0)
            break;
    }
    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < log(N) / log(v[i]) + 2; j++)
        {
            v.pb(v[i]);
        }
    }
    sort(v.begin(), v.end());
}

ll f(ll x, ll i)
{
    if (x > b || x <= 0)
        return -1e17;
    if (i == v.size())
        return x;
    ll a = 0, b = 0;
    a = f(x * v[i], i);
    b = f(x, i + 1);
    //if (a != -1e17 || b != -1e17)
    return max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tt;
    precal();
    while (tt--)
    {
        cin >> a >> b;
        ll x = f(1, 0);
        if (x >= a)
            cout << x << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
