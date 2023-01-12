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

ll n;
double ans;
vector<double> v;
vector<vector<double>> dp;
ll f(int i, int cnt)
{
    if (i == n)
    {
        if (cnt > n / 2)
            return 1;
        return 0;
    }
    // if (dp[i][cnt] >= 0)
    //     return dp[i][cnt];
    return (f(i + 1, cnt + 1) * v[i]) + (f(i + 1, cnt) * (1 - v[i]));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    dp.resize(n + 2, vector<double>(n + 2, -1));
    for (int i = 0; i < n; i++)
        ans += f(i, 0);
    cout << ans << endl;
    return 0;
}
