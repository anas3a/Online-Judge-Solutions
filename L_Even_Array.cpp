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
        int n;
        cin >> n;
        vll v(n);
        int ecnt = 0, ocnt = 0;
        for (auto &i : v)
        {
            cin >> i;
            if (i & 1)
                ocnt++;
            else
                ecnt++;
        }

        if (ocnt != n / 2)
            cout << -1 << endl;
        else if (ecnt != (n + 1) / 2)
            cout << -1 << endl;
        else
        {
            int cnt = 0;
            for (int i = 1; i < n; i += 2)
            {
                if (v[i] % 2 == 0)
                    cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}