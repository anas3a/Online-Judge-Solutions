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

    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vll v1(n1), v2(n2), v3(n3);
    for (auto &i : v1)
        cin >> i;
    for (auto &i : v2)
        cin >> i;
    for (auto &i : v3)
        cin >> i;

    vll vx1, vx2, vx3;
    ll sum = 0;
    vx1.pb(sum);
    for (int i = sz(v1) - 1; i >= 0; i--)
    {
        sum += v1[i];
        vx1.pb(sum);
    }
    sum = 0;
    vx2.pb(sum);
    for (int i = sz(v2) - 1; i >= 0; i--)
    {
        sum += v2[i];
        vx2.pb(sum);
    }
    sum = 0;
    vx3.pb(sum);
    for (int i = sz(v3) - 1; i >= 0; i--)
    {
        sum += v3[i];
        vx3.pb(sum);
    }
    ll ans = 0;
    for (int i = 0; i < sz(vx1); i++)
    {
        if (binary_search(all(vx2), vx1[i]) && binary_search(all(vx3), vx1[i]))
            ans = vx1[i];
    }
    cout << ans << endl;
    return 0;
}