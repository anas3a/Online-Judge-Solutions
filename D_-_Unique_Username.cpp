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

int z;
vvi vz;
void f(int cnt, int ind, vi vy)
{
    int x = 1;
    if (ind == 0)
    {
        vz.pb(vy);
        return;
    }
    while (true)
    {
        if (cnt - x < ind - 1)
            break;
        vy.push_back(x);
        f(cnt - x, ind - 1, vy);
        vy.pop_back();
        x++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    set<string> s;
    for (int i = 0; i < m; i++)
    {
        string sx;
        cin >> sx;
        s.insert(sx);
    }
    string ans = "-1";
    if (n == 1)
    {
        if (!s.count(v[0]) && sz(v[0]) >= 3)
            ans = v[0];
    }
    else
    {
        int cnt = 0, x = 0;
        vi vx;
        for (int k = 0; k < n; k++)
        {
            vx.pb(k), x += sz(v[k]);
        }
        z = 16 - x;
        vi vzz;
        f(16 - x, n - 1, vzz);
        bool flag = false;
        do
        {
            for (int i = 0; i < sz(vz); i++)
            {
                string tmp;
                for (int k = 0; k < sz(vx); k++)
                {
                    tmp += v[vx[k]];
                    if (k < sz(vx) - 1)
                    {
                        for (int j = 0; j < vz[i][k]; j++)
                            tmp += "_";
                    }
                }
                if (s.count(tmp))
                    cnt++;
                else
                {
                    ans = tmp;
                    flag = true;
                    break;
                }
                if (cnt >= m)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        } while (next_permutation(all(vx)));
    }
    cout << ans << endl;
    return 0;
}