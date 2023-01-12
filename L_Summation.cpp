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

ll n, m, x;
vll v;

ll f(int i)
{
    if (i == n)
        return 0;
        if (i >= x)
    return v[i] + f(i + 1);
    return f(i + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    x = n - m;
    cout << f(0) << endl;
    return 0;
}
