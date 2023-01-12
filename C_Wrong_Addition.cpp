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
        string a, s;
        cin >> a >> s;
        ll n = sz(a), m = sz(s);
        vll ans;
        bool flag = true;
        int i, j;
        for (i = n - 1, j = m - 1; i >= 0; i--)
        {
            if (j < 0)
            {
                flag = false;
                break;
            }
            if (a[i] > s[j] && j == 0)
            {
                flag = false;
                break;
            }
            if (a[i] > s[j])
            {
                string sx;
                sx += s[j - 1];
                sx += s[j];
                ll x = stoll(sx);
                ll y = a[i] - '0';
                if (x - y > 9 || x - y < 0)
                {
                    flag = false;
                    break;
                }
                ans.pb(x - y);
                j -= 2;
            }
            else
            {
                ans.pb((s[j] - '0') - (a[i] - '0'));
                j--;
            }
        }
        if (j != -1)
        {
            while (j != -1)
                ans.pb(s[j] - '0'), j--;
        }
        if (!flag)
            cout << -1 << endl;
        else
        {
            reverse(all(ans));
            bool fx = true;
            for (auto &i : ans)
            {
                if (!i && fx)
                    continue;
                cout << i;
                fx = false;
            }
            cout << endl;
        }
    }
    return 0;
}