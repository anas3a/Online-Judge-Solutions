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
double l, r;
vll v;

bool f(double x)
{
    ll sum = 0;
    for (auto &i : v)
        sum += floor(i / x);
    return sum >= k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    l = 0, r = 1e8;
    for (int i = 0; i < 100; i++)
    {
        double m = (l + r) / 2.0;
        if (f(m))
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(20) << l << endl;
    return 0;
}
