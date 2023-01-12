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

ll n, x, a, b, goal;
bool f1(ll m)
{
    return m * b <= x * a;
}
bool f2(ll m)
{
    return (m * a) / b >= goal;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ll l = 0, r = 1;
        while (f1(r))
            r *= 2;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (f1(m))
                l = m;
            else
                r = m;
        }
        goal = l;
        l = -1, r = x;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (f2(m))
                r = m;
            else
                l = m;
        }
        cout << x - r << " ";
    }
    cout << endl;
    return 0;
}
