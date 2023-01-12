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

ll n, k;
ll f(ll i, ll j, ll cnt)
{
    if (cnt == k)
        return 1;
    if (i >= n || j >= n)
        return 0;
    return f(i + 1, j, cnt) + f(i, j + 1, cnt) + f(i + 1, j + 1, cnt + 1); 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << f(0, 0, 0) << endl;
    }
    return 0;
}