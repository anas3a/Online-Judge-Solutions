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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if ((n + 1) / 2 < k)
            cout << -1 << endl;
        else
        {
            string sx(n, '.');
            vector<string> v(n, sx);
            for (int i = 0, cnt = 0; i < n && cnt < k; i++)
            {
                if (i % 2 == 0)
                    v[i][i] = 'R', cnt++;
            }
            for (auto &i : v)
                cout << i << endl;
        }
    }
    return 0;
}