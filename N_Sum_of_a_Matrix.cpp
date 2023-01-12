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

int r, c;
vvi a, b;
void sum(int i, int j)
{
    if (i >= r || j >= c)
        return;
    cout << a[i][j] + b[i][j] << " ";
    if (j + 1 == c)
    {
        cout << endl;
        return sum(i + 1, 0);
    }
    return sum(i, j + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    a.resize(r, vi(c));
    b.resize(r, vi(c));
    for (auto &i : a)
        for (auto &j : i)
            cin >> j;
    for (auto &i : b)
        for (auto &j : i)
            cin >> j;
    sum(0, 0);
    return 0;
}
