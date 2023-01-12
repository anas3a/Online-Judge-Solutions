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

int v[21][100005];
int bin_log[100005];
int main()
{

    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        bin_log[i] = bin_log[i / 2] + 1;
    int k = bin_log[n] + 1;
    for (int i = 0; i < n; i++)
        scanf("%d", &v[0][i]);

    for (int j = 1; j < k; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            v[j][i] = max(v[j - 1][i], v[j - 1][i + (1 << (j - 1))]);
        }
    }

    int m, a, b, l, r, ln;
    scanf("%d %d %d", &m, &a, &b);
    ll ans = 0;
    while (m--)
    {
        l = min(a, b), r = max(a, b);
        a += 7;
        if (a >= n - 1)
            a %= (n - 1);
        b += 11;
        if (b >= n)
            b %= n;
        ln = bin_log[r - l + 1];
        ans += max(v[ln][l], v[ln][r - (1 << ln) + 1]);
    }
    printf("%lld\n", ans);
    return 0;
}