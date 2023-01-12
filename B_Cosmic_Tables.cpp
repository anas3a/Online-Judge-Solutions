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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vvi v(n + 1, vi(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    vi mr(n + 1), mc(m + 1);
    for (int i = 1; i <= n; i++)
        mr[i] = i;
    for (int i = 1; i <= m; i++)
        mc[i] = i;
    while (k--)
    {
        char s;
        int x, y;
        cin >> s >> x >> y;
        if (s == 'c')
            swap(mc[x], mc[y]);
        else if (s == 'r')
            swap(mr[x], mr[y]);
        else
            cout << v[mr[x]][mc[y]] << "\n";
    }
    return 0;
}
