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

map<int, int> mx;
vi v;
int total = 0, n, x;

void broken_binary(int l, int m, int r, int cnt)
{
    if (l > r)
        return;
    if (v[m] == x)
    {
        mx[cnt]++;
        total++;
        return;
    }
    if (v[m] < x)
    {
        int new_l = m + 1, new_r = r;
        int md = (new_l + new_r);
        broken_binary(new_l, md / 2, new_r, cnt + 1);
        if (md & 1)
            broken_binary(new_l, (md / 2) + 1, new_r, cnt + 1);
    }
    else
    {
        int new_l = l, new_r = m - 1;
        int md = (new_l + new_r);
        broken_binary(new_l, md / 2, new_r, cnt + 1);
        if (md & 1)
            broken_binary(new_l, (md / 2) + 1, new_r, cnt + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        v.clear();
        mx.clear();
        total = 0;
        v.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        cin >> x;

        int md = (1 + n) / 2;
        broken_binary(1, md, n, 1);
        if ((1 + n) & 1)
            broken_binary(1, md + 1, n, 1);

        cout << fixed << setprecision(6) << 100 * (mx.begin()->ss / (double)total) << endl;
    }
    return 0;
}