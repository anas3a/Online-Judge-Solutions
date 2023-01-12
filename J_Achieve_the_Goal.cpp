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

    ll n, k, m;
    cin >> n >> k >> m;
    vll v(n - 1);
    ll sum = 0;
    for (auto &i : v)
        cin >> i, sum += i;
    ll ans = 0;
    bool flag = false;
    while (ans <= k)
    {
        ll sumx = sum + ans;
        ll sumz = sumx / n;
        if (sumz >= m)
        {
            flag = true;
            break;
        }
        ans++;
    }
    if (flag)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}