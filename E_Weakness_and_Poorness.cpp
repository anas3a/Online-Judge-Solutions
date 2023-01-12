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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

ll n;
vll v;
double ans;
double f(double m)
{
    double sum1 = 0, sum2 = 0, ansx = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 = max(0.0, sum1 + v[i] - m);
        sum2 = min(0.0, sum2 + v[i] - m);
        ansx = max({ansx, sum1, -sum2});
    }
    ans = ansx;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    double l = -1e9, r = 1e9;
    for (int i = 0; i < 500; i++)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double x = f(m1);
        double y = f(m2);
        if (x < y)
            r = m2;
        else
            l = m1;
    }
    cout << fixed << setprecision(12) << ans << nl;
    return 0;
}