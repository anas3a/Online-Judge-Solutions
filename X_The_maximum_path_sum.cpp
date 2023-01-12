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

ll n, m;
vvi v;

ll f(int i, int j)
{
    if (i >= n || j >= m)
    return -1e12;
    if (i == n - 1 && j == m - 1)
    return v[i][j];
    ll a = v[i][j] + f(i + 1, j);
    ll b = v[i][j] + f(i, j + 1);
    return max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    v.resize(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    cout << f(0, 0) << endl;
    return 0;
}
