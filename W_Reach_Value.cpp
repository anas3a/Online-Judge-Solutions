#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

ll n, mx = 1e13;

bool f(ll x)
{
    if (x == n)
        return true;
    if (x >= mx)
        return false;
    bool a = false, b = false;
    a = f(x * 10);
    b = f(x * 20);
    return a || b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (f(1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
