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

    vll v(26, 0);
    string s;
    cin >> s;
    for (auto &i : s)
        v[i - 'A']++;
    ll cnt = 0;
    for (auto &i : v)
    {
        if (i & 1)
            cnt++;
    }
    if ((sz(s) % 2 && cnt != 1) || (sz(s) % 2 == 0 && cnt != 0))
        cout << "NO SOLUTION" << endl;
    else
    {
        string ans;
        char x = 'x';
        for (int i = 0; i < 26; i++)
        {
            if (v[i] & 1)
            {
                x = 'A' + i;
                continue;
            }
            for (int j = 0; j < v[i] / 2; j++)
                ans += 'A' + i;
        }
        if (x != 'x')
        {
            for (int i = 0; i < v[x - 'A']; i++)
                ans += x;
        }
        for (int i = sz(ans) - 1; i >= 0; i--)
        {
            if (ans[i] == x)
                continue;
            ans.pb(ans[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
