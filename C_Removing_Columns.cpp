#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
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

    ll n, m, ans = 0;
    cin >> n >> m;
    vector<string> s(n);
    vi v(m, 1);
    for (auto &i : s)
        cin >> i;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            string sx;
            for (int k = 0; k < j; k++)
            {
                if (v[k])
                    sx += s[i][k];
            }
            for (int k = i + 1; k < n; k++)
            {
                if (s[i][j] > s[k][j])
                {
                    string sy;
                    for (int l = 0; l < j; l++)
                    {
                        if (v[l])
                            sy += s[k][l];
                    }
                    if (sx >= sy)
                    {
                        v[j] = 0;
                        ans++;
                        i = n + 1;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
