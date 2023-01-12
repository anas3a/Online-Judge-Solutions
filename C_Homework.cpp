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

    string s;
    int k;
    cin >> s >> k;
    vi v(26, 0);
    for (int i = 0; i < sz(s); i++)
        v[s[i] - 'a']++;
    vpi vx;
    for (int i = 0; i < 26; i++)
        vx.pb({v[i], i});
    sort(all(vx));
    for (int i = 0; i < sz(vx); i++)
    {
        if (k >= vx[i].ff)
            k -= vx[i].ff, vx[i].ff = 0;
        else
        {
            vx[i].ff -= k, k = 0;
            break;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < sz(vx); i++)
    {
        if (vx[i].ff != 0)
            cnt++;
        v[vx[i].ss] = vx[i].ff;
    }
    cout << cnt << endl;
    for (int i = 0; i < sz(s); i++)
    {
        if (v[s[i] - 'a'])
            cout << s[i], v[s[i] - 'a']--;
    }
    cout << endl;
    return 0;
}
