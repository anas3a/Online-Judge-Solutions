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

ll n, x;
vll v;

bool f(ll i, ll sum)
{
    if (i == n)
    {
        if (sum == x)
            return true;
        return false;
    }
    bool a = false, b = false;
    if (i != 0)
    a = f(i + 1, sum - v[i]);
    b = f(i + 1, sum + v[i]);
    return a || b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    if (f(0, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
