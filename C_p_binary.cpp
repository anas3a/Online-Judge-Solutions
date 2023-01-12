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

    ll n, p;
    cin >> n >> p;
    ll pow = 1, nx = 36;
    vll v(nx);
    for (int i = 0; i < nx; i++)
    {
        v[i] = pow + p;
        pow *= 2ll;
    }
    ll cnt = 0;
    bool flag = true;
    while (n != 0)
    {
        if (cnt >= 1e6)
        {
            flag = false;
            break;
        }
        ll ind = lower_bound(all(v), n) - v.begin();
        if (ind == 0 && v[ind] > n)
        {
            flag = false;
            break;
        }
        if (v[ind] != n)
            ind--;
        n -= v[ind];
        cnt++;
    }
    if (flag)
        cout << cnt << endl;
    else
        cout << -1 << endl;
    return 0;
}