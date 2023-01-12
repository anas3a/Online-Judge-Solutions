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
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    map<string, int> m, my;
    m["black"] = 7;
    m["pink"] = 6;
    m["blue"] = 5;
    m["brown"] = 4;
    m["green"] = 3;
    m["yellow"] = 2;
    m["red"] = 1;

    for (auto &i : v)
        my[i]++;

    int mx = 0;
    for (auto &i : v)
        mx = max(m[i], mx);
    ll ans = 0;
    if (mx == 1)
        ans = (m["red"] + 1) / 2;
    else
    {
        ll cnt = 0;
        if (my.count("red"))
        {
            cnt = my["red"] + 1;
            ans = my["red"];
            ans += cnt * mx;
        }
        for (auto &i : my)
        {
            ans += m[i.ff];
        }
        if (cnt)
        {
            ans -= 1;
            ans -= mx;
        }
    }
    cout << ans << endl;
    return 0;
}