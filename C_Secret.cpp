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

    int n, k;
    cin >> n >> k;
    if (k * 3 > n)
    {
        cout << -1 << endl;
        return 0;
    }
    vi v(n + 1, 0);
    int x = 1, y = n - 1;
    for (int i = 1; i <= k; i++)
    {
        if (i < k)
        {
            v[x] = i;
            v[x + 1] = i;
            x += 2;
            v[y] = i, y--;
        }
        else
        {
            while (v[x] == 0)
                v[x] = i, x++;
            v[n] = i;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
