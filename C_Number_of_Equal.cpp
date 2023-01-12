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

    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    ll ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < m && b[j] < a[i])
            j++;
        if (a[i] == b[j])
        {
            ll z = a[i], x = 0, y = 0;
            while (j < m && b[j] == a[i])
                x++, j++;
            while (i < n && a[i] == z)
                y++, i++;
            i--;
            ans += x * y;
        }
    }
    cout << ans << endl;
    return 0;
}
