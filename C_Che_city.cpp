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

    ll n, r;
    cin >> n >> r;
    vll v(n);
    for (auto &i : v)
        cin >> i;
    ll l = 0, ans = 0, x;
    for (int i = 0; i < n; i++)
    {
        while (v[i] - v[l] > r)
            l++;
        ans += l;
    }
    cout << ans << endl;
    return 0;
}
