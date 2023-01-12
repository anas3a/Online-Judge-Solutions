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

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v1(n), v2(n), vx(1002, 0), vy(1002, 0);
        for (auto &i : v1)
            cin >> i, vx[i]++;
        for (auto &i : v2)
            cin >> i, vy[i]++;
        sort(all(v1));
        sort(all(v2));
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = n - 1; j >= 0; j--)
            {
                if (v1[i] > v2[j] && vy[v2[j]])
                {
                    ans += 2;
                    flag = true;
                    vy[v2[j]]--;
                    break;
                }
            }
            if (flag)
                vx[v1[i]]--;
        }
        for (int i = 1; i <= 1000; i++)
        {
            if (vx[i] && vy[i])
                ans += min(vx[i], vy[i]);
        }
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}