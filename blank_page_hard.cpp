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

vll v1, v2;
string s1, s2;
ll w;

ll cntf(vll vx, ll n)
{
    ll cx = 0;
    for (int i = 0, j = n; i < sz(vx); i++)
    {
        if (j >= vx[i])
        {
            j -= vx[i];
        }
        else
        {
            if (vx[i] <= j)
            {
                cx++;
                j = n - vx[i];
            }
            else
            {
                cx += (vx[i] + n - 1) / n;
                j = n - (vx[i] % n);
            }
        }
        if (i != sz(vx) - 1)
        {
            j--;
            if (j < 0)
            {
                j = n - 1;
                cx++;
            }
        }
    }
    return cx;
}

// bool f(ll m)
// {
//     ll x = cnt(v1, m);
//     ll y = cnt(v2, w - m);
//     return x <= y;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2 >> w;
        v1.clear(), v2.clear();
        ll cnt = 0;
        for (auto &i : s1)
        {
            if (i == '-')
            {
                v1.pb(cnt);
                cnt = 0;
            }
            else
                cnt++;
        }
        v1.pb(cnt);
        cnt = 0;
        for (auto &i : s2)
        {
            if (i == '-')
            {
                v2.pb(cnt);
                cnt = 0;
            }
            else
                cnt++;
        }
        v2.pb(cnt);
        ll l = 1, r = w;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (cntf(v1, m) == cntf(v2, w - m))
                break;
            else if (cntf(v1, m) > cntf(v2, w - m))
                l = m;
            else
                r = m;
        }
        cout << l << endl;
        cout << r << endl;
    }
    return 0;
}