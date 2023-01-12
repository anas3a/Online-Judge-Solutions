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

string a, b, c;
int dp[102][102];
vector<string> ans;
int f(int i, int j, string s)
{
    if (i == sz(a) || j == sz(b))
    {
        ans.pb(s);
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
    {
        s += a[i];
        return dp[i][j] = 1 + f(i + 1, j + 1, s);
    }
    return dp[i][j] = max(f(i + 1, j, s + a[i]), f(i, j + 1, s + b[i]));
}
// void build(int i, int j)
// {
//     if (i == sz(a) || j == sz(b))
//         return;
//     if (a[i] == b[j])
//     {
//         c += a[i];
//         return build(i + 1, j + 1);
//     }
//     if (f(i, j) == f(i + 1, j))
//         return build(i + 1, j);
//     else
//         return build(i, j + 1);
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));
        cout << "Case " << ++cs << ": ";
        ll mx = f(0, 0, "");

        // if (mx == 0)
        //     cout << ":(" << endl;
        // else
        // {
        //     string ans;
        //     for (int i = 0; i < 100; i++)
        //     {
        //         for (int j = 0; j < 100; j++)
        //         {
        //             if (dp[i][j] == mx)
        //             {
        //                 c.clear();
        //                 build(i, j);
        //                 if (ans.empty())
        //                     ans = c;
        //                 else
        //                     ans = min(ans, c);
        //             }
        //         }
        //     }
        //     cout << ans << endl;
        // }
        sort(all(ans));
        for (auto &i : ans)
            cout << i << endl;
        ans.clear();
    }
    return 0;
}
