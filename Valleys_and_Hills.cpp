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
        ll n, m;
        cin >> n >> m;
        string ans;
        if (n >= m)
        {
            ll ch = 0, cv = 0;
            ans = "01";
            while (true)
            {
                if (cv >= m && ch >= n)
                    break;
                if (cv < m)
                    ch++, ans += "0";
                else
                    ch++, ans += "00";
                if (cv >= m && ch >= n)
                    break;
                cv++, ans += "1";
            }
        }
        else
        {
            ll ch = 0, cv = 0;
            ans = "10";
            while (true)
            {
                if (cv >= m && ch >= n)
                    break;
                if (ch < n)
                    cv++, ans += "1";
                else
                    cv++, ans += "11";
                if (cv >= m && ch >= n)
                    break;
                ch++, ans += "0";
            }
        }
        ll z = sz(ans);
        if (ans[z - 1] == ans[z - 2])
            z--;
        cout << z << endl;
        for (int i = 0; i < z; i++)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}