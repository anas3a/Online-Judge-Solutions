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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        string s;
        cin >> s;
        vpl vmn, vmx;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                vmn.pb({v[i], i});
            else
                vmx.pb({v[i], i});
        }
        sort(all(vmn));
        sort(all(vmx));
        vll ans(n);
        ll x = 0;
        for (int i = 0; i < sz(vmn); i++)
        {
            ans[vmn[i].ss] = ++x;
        }
        for (int i = 0; i < sz(vmx); i++)
        {
            ans[vmx[i].ss] = ++x;
        }
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}