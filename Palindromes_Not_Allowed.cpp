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
        ll n;
        string s;
        cin >> n >> s;
        vi v(26, 0);
        for (auto &i : s)
            v[i - 'a']++;
        string ans;
        bool flag = false;
        int x = -1, y = -1, j = 0;
        vpl vy;
        for (int i = 0; i < 26; i++)
        {
            if (v[i])
            {
                vy.pb({v[i], i});
            }
        }
        sort(rall(vy));
        for (int i = 0; i < n; i++)
        {
            bool flagx = true;
            for (int j = 0; j < sz(vy); j++)
            {
                if (vy[j].ff && x != j && y != j)
                {
                    x = y;
                    y = j;
                    ans += char('a' + vy[j].ss);
                    flagx = false;
                    vy[j].ff--;
                    break;
                }
            }
            if (flagx)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << ans << endl;
        }
    }
    return 0;
}