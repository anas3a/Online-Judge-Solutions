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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi v(n + 1);
        map<int, int> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            m[v[i]] = i;
        }
        int ans = -1;
        for (int i = n; i > 0; i--)
        {
            for (int j = 1000; j >= 1; j--)
            {
                if (__gcd(j, v[i]) == 1 && m[j])
                    ans = max(ans, i + m[j]);
            }
        }
        cout << ans << nl;
    }
    return 0;
}