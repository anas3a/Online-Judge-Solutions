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
    vi v(n);
    for (auto &i : v)
        cin >> i;
    while (k--)
    {
        int a;
        cin >> a;
        int l = -1, r = n;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (v[m] < a)
                l = m;
            else
                r = m;
        }
        cout << r + 1 << endl;
    }
    return 0;
}
