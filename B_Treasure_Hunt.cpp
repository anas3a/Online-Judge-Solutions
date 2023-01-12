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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vll v(200, 0);
    vector<pair<ll, string>> vx;
    for (int i = 0; i < sz(s1); i++)
        v[s1[i] - 'A']++;
    sort(rall(v));
    vx.pb({min(v[0] + n, (ll)sz(s1)), "Kuro"});
    if (v[0] == sz(s1) && n == 1)
        vx[0].ff--;
    v.clear();
    v.resize(200, 0);
    for (int i = 0; i < sz(s2); i++)
        v[s2[i] - 'A']++;
    sort(rall(v));
    vx.pb({min(v[0] + n, (ll)sz(s2)), "Shiro"});
    if (v[0] == sz(s2) && n == 1)
        vx[1].ff--;
    v.clear();
    v.resize(200, 0);
    for (int i = 0; i < sz(s3); i++)
        v[s3[i] - 'A']++;
    sort(rall(v));
    vx.pb({min(v[0] + n, (ll)sz(s3)), "Katie"});
    if (v[0] == sz(s3) && n == 1)
        vx[2].ff--;
    sort(rall(vx));
    if (vx[0].ff == vx[1].ff)
        cout << "Draw" << endl;
    else
        cout << vx[0].ss << endl;
    return 0;
}
