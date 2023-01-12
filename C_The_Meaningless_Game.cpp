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

ll fx(ll a)
{
    ll l = 0, r = 1e6 + 5;
    while (l != r)
    {
        ll m = (l + r + 1) / 2;
        if (m * m * m > a)
            r = m - 1;
        else
            l = m;
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    scanf("%lld", &t);
    while (t--)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll x = fx(a * b);
        if (x * x * x != a * b || a % x != 0 || b % x != 0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
